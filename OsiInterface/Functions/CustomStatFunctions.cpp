#include <stdafx.h>
#include "FunctionLibrary.h"
#include <OsirisProxy.h>
#include "PropertyMaps.h"

namespace osidbg
{
	namespace func
	{
		esv::CustomStatDefinitionComponent * FindCustomStatDefinitionByName(char const * name)
		{
			std::wstring wstrName = FromUTF8(name);

			auto entityWorld = GetEntityWorld();
			auto statSystem = entityWorld->GetCustomStatSystem();
			auto & defnHandles = statSystem->CustomStatDefinitionHandles.Set;

			for (uint32_t i = 0; i < defnHandles.Size; i++) {
				auto handle = defnHandles.Buf[i].Handle;
				auto statDefn = entityWorld->FindCustomStatDefinitionComponentByHandle(handle);
				if (statDefn != nullptr && wcscmp(statDefn->Name.GetPtr(), wstrName.c_str()) == 0) {
					return statDefn;
				}
			}

			OsiError("Could not find custom stat definition '" << name << "'");
			return nullptr;
		}

		esv::CustomStatDefinitionComponent * FindCustomStatDefinitionById(char const * id)
		{
			auto fs = ToFixedString(id);
			if (!fs) {
				OsiError("Custom stat definition '" << id << "' is not in fixed string table");
				return nullptr;
			}

			auto entityWorld = GetEntityWorld();
			auto statSystem = entityWorld->GetCustomStatSystem();
			auto & defnHandles = statSystem->CustomStatDefinitionHandles.Set;

			for (uint32_t i = 0; i < defnHandles.Size; i++) {
				auto handle = defnHandles.Buf[i].Handle;
				auto statDefn = entityWorld->FindCustomStatDefinitionComponentByHandle(handle);
				if (statDefn != nullptr && statDefn->Id == fs) {
					return statDefn;
				}
			}

			OsiError("Could not find custom stat definition '" << id << "'");
			return nullptr;
		}

		void ProcessCustomStatsMessage(eocnet::Message * msg)
		{
			struct DummyType
			{
				uint16_t unkn1;
				uint16_t unkn2;
			};

			DummyType dummy1;
			dummy1.unkn2 = 0;

			auto processMsg = gOsirisProxy->GetLibraryManager().EsvCustomStatsProtocolProcessMsg;
			if (processMsg == nullptr) {
				OsiError("esv::CustomStatsProtocol::ProcessMsg not found!");
				return;
			}

			processMsg(nullptr, nullptr, &dummy1, msg);
		}

		bool CharacterGetCustomStat(OsiArgumentDesc & args)
		{
			auto character = FindCharacterByNameGuid(args[0].String);
			auto statId = args[1].String;
			auto & statValue = args[2].Int32;

			auto statDefn = FindCustomStatDefinitionById(statId);
			if (statDefn == nullptr) return false;

			auto entityWorld = GetEntityWorld();
			auto statsComponent = entityWorld->GetCustomStatsComponentByEntityHandle(character->Base.EntityObjectHandle);
			if (statsComponent == nullptr) {
				OsiError("Character has no CustomStatsComponent");
				return false;
			}

			auto value = statsComponent->StatValues.Find(statDefn->Id.Str);
			if (value == nullptr) {
				OsiWarn("Character has no custom stat named '" << statId << "'");
				return false;
			}

			statValue = *value;
			return true;
		}

		void CharacterSyncCustomStats(esv::Character * character, eoc::CustomStatsComponent * stats,
			FixedString statKey, int statValue)
		{
			eocnet::CustomStatsSyncMessage statSyncMsg;
			if (stats == nullptr) {
				statSyncMsg.MessageId = NetMessage::NETMSG_CUSTOM_STATS_CREATE;
			} else {
				statSyncMsg.MessageId = NetMessage::NETMSG_CUSTOM_STATS_UPDATE;
			}

			// FIXME - memory leak!
			statSyncMsg.Stats.Set.Buf = GameAlloc<eocnet::CustomStatsSyncInfo>(1);
			statSyncMsg.Stats.Set.Capacity = 1;
			statSyncMsg.Stats.Set.Size = 1;

			auto entityWorld = GetEntityWorld();
			auto netComponent = entityWorld->GetNetComponentByEntityHandle(character->Base.EntityObjectHandle);

			auto & stat = statSyncMsg.Stats.Set.Buf[0];
			stat.NetId = netComponent->NetID;
			stat.Stats.Init(0x25);

			if (stats != nullptr) {
				stats->StatValues.Iterate([&stat](FixedString key, int value) {
					stat.Stats.Add(key, value);
				});
			}

			stat.Stats.Add(statKey, statValue);

			ProcessCustomStatsMessage(&statSyncMsg);
		}

		void CharacterSetCustomStat(OsiArgumentDesc const & args)
		{
			auto character = FindCharacterByNameGuid(args[0].String);
			auto statId = args[1].String;
			auto statValue = args[2].Int32;

			auto statDefn = FindCustomStatDefinitionById(statId);
			if (statDefn == nullptr) return;

			auto entityWorld = GetEntityWorld();
			auto statsComponent = entityWorld->GetCustomStatsComponentByEntityHandle(character->Base.EntityObjectHandle);

			CharacterSyncCustomStats(character, statsComponent, statDefn->Id, statValue);
		}

		void CreateCustomStatInternal(char const * name, char const * description)
		{
			eocnet::CustomStatsDefinitionSyncMessage msg;
			msg.MessageId = NetMessage::NETMSG_CUSTOM_STATS_DEFINITION_CREATE;

			// FIXME - memory leak!
			msg.StatDefns.Set.Buf = GameAlloc<eocnet::CustomStatDefinitionSyncInfo>(1);
			msg.StatDefns.Set.Capacity = 1;
			msg.StatDefns.Set.Size = 1;

			std::wstring wstrName = FromUTF8(name);
			std::wstring wstrDescription = FromUTF8(description);

			auto & defn = msg.StatDefns.Set.Buf[0];
			defn.Name.Set(wstrName);
			defn.Description.Set(wstrDescription);

			ProcessCustomStatsMessage(&msg);
		}

		bool CreateCustomStat(OsiArgumentDesc & args)
		{
			auto statName = args[0].String;
			auto statDescription = args[1].String;
			auto & statId = args[2].String;

			auto statDefn = FindCustomStatDefinitionByName(statName);
			if (statDefn != nullptr) {
				OsiWarn("Custom stat '" << statName << "' already exists!");
				statId = statDefn->Id.Str;
				return true;
			}

			CreateCustomStatInternal(statName, statDescription);

			statDefn = FindCustomStatDefinitionByName(statName);
			if (statDefn != nullptr) {
				statId = statDefn->Id.Str;
				return true;
			} else {
				OsiWarn("Unable to create custom stat '" << statName << "' - not found after create message ?!");
				return false;
			}
		}

		bool GetCustomStat(OsiArgumentDesc & args)
		{
			auto statName = args[0].String;
			auto & statId = args[1].String;

			auto statDefn = FindCustomStatDefinitionByName(statName);
			if (statDefn != nullptr) {
				statId = statDefn->Id.Str;
				return true;
			} else {
				OsiWarn("Custom stat '" << statName << "' does not exist!");
				return false;
			}
		}
	}

	void CustomFunctionLibrary::RegisterCustomStatFunctions()
	{
		auto & functionMgr = osiris_.GetCustomFunctionManager();

		auto characterGetCustomStat = std::make_unique<CustomQuery>(
			"NRD_CharacterGetCustomStat",
			std::vector<CustomFunctionParam>{
				{ "Character", ValueType::CharacterGuid, FunctionArgumentDirection::In },
				{ "StatId", ValueType::GuidString, FunctionArgumentDirection::In },
				{ "Value", ValueType::Integer, FunctionArgumentDirection::Out },
			},
			&func::CharacterGetCustomStat
		);
		functionMgr.Register(std::move(characterGetCustomStat));


		auto characterSetCustomStat = std::make_unique<CustomCall>(
			"NRD_CharacterSetCustomStat",
			std::vector<CustomFunctionParam>{
				{ "Character", ValueType::CharacterGuid, FunctionArgumentDirection::In },
				{ "StatId", ValueType::GuidString, FunctionArgumentDirection::In },
				{ "Value", ValueType::Integer, FunctionArgumentDirection::In },
			},
			&func::CharacterSetCustomStat
		);
		functionMgr.Register(std::move(characterSetCustomStat));


		auto createCustomStat = std::make_unique<CustomQuery>(
			"NRD_CreateCustomStat",
			std::vector<CustomFunctionParam>{
				{ "Name", ValueType::String, FunctionArgumentDirection::In },
				{ "Description", ValueType::String, FunctionArgumentDirection::In },
				{ "StatId", ValueType::GuidString, FunctionArgumentDirection::Out },
			},
			&func::CreateCustomStat
		);
		functionMgr.Register(std::move(createCustomStat));


		auto getCustomStat = std::make_unique<CustomQuery>(
			"NRD_GetCustomStat",
			std::vector<CustomFunctionParam>{
				{ "Name", ValueType::String, FunctionArgumentDirection::In },
				{ "StatId", ValueType::GuidString, FunctionArgumentDirection::Out },
			},
			&func::GetCustomStat
		);
		functionMgr.Register(std::move(getCustomStat));
	}

}