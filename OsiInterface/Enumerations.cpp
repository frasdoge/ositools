#include "stdafx.h"

#include <GameDefinitions/BaseTypes.h>
#include <GameDefinitions/Enumerations.h>

namespace osidbg
{
	EnumInfo<ComponentType>::Label const EnumInfo<ComponentType>::Values[] = {
		{ ComponentType::AnimationBlueprint, "AnimationBlueprint" },
		{ ComponentType::Spline, "Spline" },
		{ ComponentType::Combat, "Combat" },
		{ ComponentType::CustomStats, "CustomStats" },
		{ ComponentType::GameMaster, "GameMaster" },
		{ ComponentType::GMJournalNode, "GMJournalNode" },
		{ ComponentType::Container, "Container" },
		{ ComponentType::ContainerElement, "ContainerElement" },
		{ ComponentType::Net, "Net" },
		{ ComponentType::OverviewMap, "OverviewMap" },
		{ ComponentType::Note, "Note" },
		{ ComponentType::Vignette, "Vignette" },
		{ ComponentType::CustomStatDefinition, "CustomStatDefinition" },
		{ ComponentType::Item, "Item" },
		{ ComponentType::Character, "Character" },
		{ ComponentType::Egg, "Egg" },
		{ ComponentType::Projectile, "Projectile" },
	};


	EnumInfo<PlayerUpgradeAttribute>::Label const EnumInfo<PlayerUpgradeAttribute>::Values[] = {
		{ PlayerUpgradeAttribute::Strength, "Strength" },
		{ PlayerUpgradeAttribute::Finesse, "Finesse" },
		{ PlayerUpgradeAttribute::Intelligence, "Intelligence" },
		{ PlayerUpgradeAttribute::Constitution, "Constitution" },
		{ PlayerUpgradeAttribute::Memory, "Memory" },
		{ PlayerUpgradeAttribute::Wits, "Wits" },
	};


	EnumInfo<StatGetterType>::Label const EnumInfo<StatGetterType>::Values[] = {
		{ StatGetterType::MaxMp, "MaxMp" },
		{ StatGetterType::APStart, "APStart" },
		{ StatGetterType::APRecovery, "APRecovery" },
		{ StatGetterType::APMaximum, "APMaximum" },
		{ StatGetterType::Strength, "Strength" },
		{ StatGetterType::Finesse, "Finesse" },
		{ StatGetterType::Intelligence, "Intelligence" },
		{ StatGetterType::Vitality, "Vitality" },
		{ StatGetterType::Memory, "Memory" },
		{ StatGetterType::Wits, "Wits" },
		{ StatGetterType::Accuracy, "Accuracy" },
		{ StatGetterType::Dodge, "Dodge" },
		{ StatGetterType::CriticalChance, "CriticalChance" },
		{ StatGetterType::FireResistance, "FireResistance" },
		{ StatGetterType::EarthResistance, "EarthResistance" },
		{ StatGetterType::WaterResistance, "WaterResistance" },
		{ StatGetterType::AirResistance, "AirResistance" },
		{ StatGetterType::PoisonResistance, "PoisonResistance" },
		{ StatGetterType::ShadowResistance, "ShadowResistance" },
		{ StatGetterType::CustomResistance, "CustomResistance" },
		{ StatGetterType::LifeSteal, "LifeSteal" },
		{ StatGetterType::Sight, "Sight" },
		{ StatGetterType::Hearing, "Hearing" },
		{ StatGetterType::Movement, "Movement" },
		{ StatGetterType::Initiative, "Initiative" },
		{ StatGetterType::Unknown, "Unknown" },
		{ StatGetterType::ChanceToHitBoost, "ChanceToHitBoost" }
	};


	EnumInfo<RequirementType>::Label const EnumInfo<RequirementType>::Values[] = {
		{ RequirementType::None, "None" },
		{ RequirementType::Level, "Level" },
		{ RequirementType::Strength, "Strength" },
		{ RequirementType::Finesse, "Finesse" },
		{ RequirementType::Intelligence, "Intelligence" },
		{ RequirementType::Constitution, "Constitution" },
		{ RequirementType::Memory, "Memory" },
		{ RequirementType::Wits, "Wits" },
		{ RequirementType::WarriorLore, "WarriorLore" },
		{ RequirementType::RangerLore, "RangerLore" },
		{ RequirementType::RogueLore, "RogueLore" },
		{ RequirementType::SingleHanded, "SingleHanded" },
		{ RequirementType::TwoHanded, "TwoHanded" },
		{ RequirementType::PainReflection, "PainReflection" },
		{ RequirementType::Ranged, "Ranged" },
		{ RequirementType::Shield, "Shield" },
		{ RequirementType::Reflexes, "Reflexes" },
		{ RequirementType::PhysicalArmorMastery, "PhysicalArmorMastery" },
		{ RequirementType::MagicArmorMastery, "MagicArmorMastery" },
		{ RequirementType::Vitality, "Vitality" },
		{ RequirementType::Sourcery, "Sourcery" },
		{ RequirementType::Telekinesis, "Telekinesis" },
		{ RequirementType::FireSpecialist, "FireSpecialist" },
		{ RequirementType::WaterSpecialist, "WaterSpecialist" },
		{ RequirementType::AirSpecialist, "AirSpecialist" },
		{ RequirementType::EarthSpecialist, "EarthSpecialist" },
		{ RequirementType::Necromancy, "Necromancy" },
		{ RequirementType::Summoning, "Summoning" },
		{ RequirementType::Polymorph, "Polymorph" },
		{ RequirementType::Repair, "Repair" },
		{ RequirementType::Sneaking, "Sneaking" },
		{ RequirementType::Pickpocket, "Pickpocket" },
		{ RequirementType::Thievery, "Thievery" },
		{ RequirementType::Loremaster, "Loremaster" },
		{ RequirementType::Crafting, "Crafting" },
		{ RequirementType::Barter, "Barter" },
		{ RequirementType::Charm, "Charm" },
		{ RequirementType::Intimidate, "Intimidate" },
		{ RequirementType::Reason, "Reason" },
		{ RequirementType::Persuasion, "Persuasion" },
		{ RequirementType::Leadership, "Leadership" },
		{ RequirementType::Luck, "Luck" },
		{ RequirementType::DualWielding, "DualWielding" },
		{ RequirementType::Wand, "Wand" },
		{ RequirementType::Perseverance, "Perseverance" },
		{ RequirementType::TALENT_ItemMovement, "TALENT_ItemMovement" },
		{ RequirementType::TALENT_ItemCreation, "TALENT_ItemCreation" },
		{ RequirementType::TALENT_Flanking, "TALENT_Flanking" },
		{ RequirementType::TALENT_AttackOfOpportunity, "TALENT_AttackOfOpportunity" },
		{ RequirementType::TALENT_Backstab, "TALENT_Backstab" },
		{ RequirementType::TALENT_Trade, "TALENT_Trade" },
		{ RequirementType::TALENT_Lockpick, "TALENT_Lockpick" },
		{ RequirementType::TALENT_ChanceToHitRanged, "TALENT_ChanceToHitRanged" },
		{ RequirementType::TALENT_ChanceToHitMelee, "TALENT_ChanceToHitMelee" },
		{ RequirementType::TALENT_Damage, "TALENT_Damage" },
		{ RequirementType::TALENT_ActionPoints, "TALENT_ActionPoints" },
		{ RequirementType::TALENT_ActionPoints2, "TALENT_ActionPoints2" },
		{ RequirementType::TALENT_Criticals, "TALENT_Criticals" },
		{ RequirementType::TALENT_IncreasedArmor, "TALENT_IncreasedArmor" },
		{ RequirementType::TALENT_Sight, "TALENT_Sight" },
		{ RequirementType::TALENT_ResistFear, "TALENT_ResistFear" },
		{ RequirementType::TALENT_ResistKnockdown, "TALENT_ResistKnockdown" },
		{ RequirementType::TALENT_ResistStun, "TALENT_ResistStun" },
		{ RequirementType::TALENT_ResistPoison, "TALENT_ResistPoison" },
		{ RequirementType::TALENT_ResistSilence, "TALENT_ResistSilence" },
		{ RequirementType::TALENT_ResistDead, "TALENT_ResistDead" },
		{ RequirementType::TALENT_Carry, "TALENT_Carry" },
		{ RequirementType::TALENT_Kinetics, "TALENT_Kinetics" },
		{ RequirementType::TALENT_Repair, "TALENT_Repair" },
		{ RequirementType::TALENT_ExpGain, "TALENT_ExpGain" },
		{ RequirementType::TALENT_ExtraStatPoints, "TALENT_ExtraStatPoints" },
		{ RequirementType::TALENT_ExtraSkillPoints, "TALENT_ExtraSkillPoints" },
		{ RequirementType::TALENT_Durability, "TALENT_Durability" },
		{ RequirementType::TALENT_Awareness, "TALENT_Awareness" },
		{ RequirementType::TALENT_Vitality, "TALENT_Vitality" },
		{ RequirementType::TALENT_FireSpells, "TALENT_FireSpells" },
		{ RequirementType::TALENT_WaterSpells, "TALENT_WaterSpells" },
		{ RequirementType::TALENT_AirSpells, "TALENT_AirSpells" },
		{ RequirementType::TALENT_EarthSpells, "TALENT_EarthSpells" },
		{ RequirementType::TALENT_Charm, "TALENT_Charm" },
		{ RequirementType::TALENT_Intimidate, "TALENT_Intimidate" },
		{ RequirementType::TALENT_Reason, "TALENT_Reason" },
		{ RequirementType::TALENT_Luck, "TALENT_Luck" },
		{ RequirementType::TALENT_Initiative, "TALENT_Initiative" },
		{ RequirementType::TALENT_InventoryAccess, "TALENT_InventoryAccess" },
		{ RequirementType::TALENT_AvoidDetection, "TALENT_AvoidDetection" },
		{ RequirementType::TALENT_AnimalEmpathy, "TALENT_AnimalEmpathy" },
		{ RequirementType::TALENT_Escapist, "TALENT_Escapist" },
		{ RequirementType::TALENT_StandYourGround, "TALENT_StandYourGround" },
		{ RequirementType::TALENT_SurpriseAttack, "TALENT_SurpriseAttack" },
		{ RequirementType::TALENT_LightStep, "TALENT_LightStep" },
		{ RequirementType::TALENT_ResurrectToFullHealth, "TALENT_ResurrectToFullHealth" },
		{ RequirementType::TALENT_Scientist, "TALENT_Scientist" },
		{ RequirementType::TALENT_Raistlin, "TALENT_Raistlin" },
		{ RequirementType::TALENT_MrKnowItAll, "TALENT_MrKnowItAll" },
		{ RequirementType::TALENT_WhatARush, "TALENT_WhatARush" },
		{ RequirementType::TALENT_FaroutDude, "TALENT_FaroutDude" },
		{ RequirementType::TALENT_Leech, "TALENT_Leech" },
		{ RequirementType::TALENT_ElementalAffinity, "TALENT_ElementalAffinity" },
		{ RequirementType::TALENT_FiveStarRestaurant, "TALENT_FiveStarRestaurant" },
		{ RequirementType::TALENT_Bully, "TALENT_Bully" },
		{ RequirementType::TALENT_ElementalRanger, "TALENT_ElementalRanger" },
		{ RequirementType::TALENT_LightningRod, "TALENT_LightningRod" },
		{ RequirementType::TALENT_Politician, "TALENT_Politician" },
		{ RequirementType::TALENT_WeatherProof, "TALENT_WeatherProof" },
		{ RequirementType::TALENT_LoneWolf, "TALENT_LoneWolf" },
		{ RequirementType::TALENT_Zombie, "TALENT_Zombie" },
		{ RequirementType::TALENT_Demon, "TALENT_Demon" },
		{ RequirementType::TALENT_IceKing, "TALENT_IceKing" },
		{ RequirementType::TALENT_Courageous, "TALENT_Courageous" },
		{ RequirementType::TALENT_GoldenMage, "TALENT_GoldenMage" },
		{ RequirementType::TALENT_WalkItOff, "TALENT_WalkItOff" },
		{ RequirementType::TALENT_FolkDancer, "TALENT_FolkDancer" },
		{ RequirementType::TALENT_SpillNoBlood, "TALENT_SpillNoBlood" },
		{ RequirementType::TALENT_Stench, "TALENT_Stench" },
		{ RequirementType::TALENT_Kickstarter, "TALENT_Kickstarter" },
		{ RequirementType::TALENT_WarriorLoreNaturalArmor, "TALENT_WarriorLoreNaturalArmor" },
		{ RequirementType::TALENT_WarriorLoreNaturalHealth, "TALENT_WarriorLoreNaturalHealth" },
		{ RequirementType::TALENT_WarriorLoreNaturalResistance, "TALENT_WarriorLoreNaturalResistance" },
		{ RequirementType::TALENT_RangerLoreArrowRecover, "TALENT_RangerLoreArrowRecover" },
		{ RequirementType::TALENT_RangerLoreEvasionBonus, "TALENT_RangerLoreEvasionBonus" },
		{ RequirementType::TALENT_RangerLoreRangedAPBonus, "TALENT_RangerLoreRangedAPBonus" },
		{ RequirementType::TALENT_RogueLoreDaggerAPBonus, "TALENT_RogueLoreDaggerAPBonus" },
		{ RequirementType::TALENT_RogueLoreDaggerBackStab, "TALENT_RogueLoreDaggerBackStab" },
		{ RequirementType::TALENT_RogueLoreMovementBonus, "TALENT_RogueLoreMovementBonus" },
		{ RequirementType::TALENT_RogueLoreHoldResistance, "TALENT_RogueLoreHoldResistance" },
		{ RequirementType::TALENT_NoAttackOfOpportunity, "TALENT_NoAttackOfOpportunity" },
		{ RequirementType::TALENT_WarriorLoreGrenadeRange, "TALENT_WarriorLoreGrenadeRange" },
		{ RequirementType::TALENT_RogueLoreGrenadePrecision, "TALENT_RogueLoreGrenadePrecision" },
		{ RequirementType::TALENT_ExtraWandCharge, "TALENT_ExtraWandCharge" },
		{ RequirementType::TALENT_DualWieldingDodging, "TALENT_DualWieldingDodging" },
		{ RequirementType::TALENT_Human_Civil, "TALENT_Human_Civil" },
		{ RequirementType::TALENT_Human_Inventive, "TALENT_Human_Inventive" },
		{ RequirementType::TALENT_Dwarf_Sneaking, "TALENT_Dwarf_Sneaking" },
		{ RequirementType::TALENT_Dwarf_Sturdy, "TALENT_Dwarf_Sturdy" },
		{ RequirementType::TALENT_Elf_CorpseEater, "TALENT_Elf_CorpseEater" },
		{ RequirementType::TALENT_Elf_Lore, "TALENT_Elf_Lore" },
		{ RequirementType::TALENT_Lizard_Persuasion, "TALENT_Lizard_Persuasion" },
		{ RequirementType::TALENT_Lizard_Resistance, "TALENT_Lizard_Resistance" },
		{ RequirementType::TALENT_Perfectionist, "TALENT_Perfectionist" },
		{ RequirementType::TALENT_Executioner, "TALENT_Executioner" },
		{ RequirementType::TALENT_QuickStep, "TALENT_QuickStep" },
		{ RequirementType::TALENT_ViolentMagic, "TALENT_ViolentMagic" },
		{ RequirementType::TALENT_Memory, "TALENT_Memory" },
		{ RequirementType::TALENT_LivingArmor, "TALENT_LivingArmor" },
		{ RequirementType::TALENT_Torturer, "TALENT_Torturer" },
		{ RequirementType::TALENT_Ambidextrous, "TALENT_Ambidextrous" },
		{ RequirementType::TALENT_Unstable, "TALENT_Unstable" },
		{ RequirementType::TALENT_Sourcerer, "TALENT_Sourcerer" },
		{ RequirementType::TRAIT_Forgiving, "TRAIT_Forgiving" },
		{ RequirementType::TRAIT_Vindictive, "TRAIT_Vindictive" },
		{ RequirementType::TRAIT_Bold, "TRAIT_Bold" },
		{ RequirementType::TRAIT_Timid, "TRAIT_Timid" },
		{ RequirementType::TRAIT_Altruistic, "TRAIT_Altruistic" },
		{ RequirementType::TRAIT_Egotistical, "TRAIT_Egotistical" },
		{ RequirementType::TRAIT_Independent, "TRAIT_Independent" },
		{ RequirementType::TRAIT_Obedient, "TRAIT_Obedient" },
		{ RequirementType::TRAIT_Pragmatic, "TRAIT_Pragmatic" },
		{ RequirementType::TRAIT_Romantic, "TRAIT_Romantic" },
		{ RequirementType::TRAIT_Spiritual, "TRAIT_Spiritual" },
		{ RequirementType::TRAIT_Materialistic, "TRAIT_Materialistic" },
		{ RequirementType::TRAIT_Righteous, "TRAIT_Righteous" },
		{ RequirementType::TRAIT_Renegade, "TRAIT_Renegade" },
		{ RequirementType::TRAIT_Blunt, "TRAIT_Blunt" },
		{ RequirementType::TRAIT_Considerate, "TRAIT_Considerate" },
		{ RequirementType::TRAIT_Compassionate, "TRAIT_Compassionate" },
		{ RequirementType::TRAIT_Heartless, "TRAIT_Heartless" },
		{ RequirementType::Combat, "Combat" },
		{ RequirementType::MinKarma, "MinKarma" },
		{ RequirementType::MaxKarma, "MaxKarma" },
		{ RequirementType::Immobile, "Immobile" },
		{ RequirementType::Tag, "Tag" }
	};

	EnumInfo<WeaponType>::Label const EnumInfo<WeaponType>::Values[] = {
		{ WeaponType::None, "None" },
		{ WeaponType::Sword, "Sword" },
		{ WeaponType::Club, "Club" },
		{ WeaponType::Axe, "Axe" },
		{ WeaponType::Staff, "Staff" },
		{ WeaponType::Bow, "Bow" },
		{ WeaponType::Crossbow, "Crossbow" },
		{ WeaponType::Spear, "Spear" },
		{ WeaponType::Knife, "Knife" },
		{ WeaponType::Wand, "Wand" },
		{ WeaponType::Arrow, "Arrow" },
		{ WeaponType::Rifle, "Rifle" }
	};

	EnumInfo<AbilityType>::Label const EnumInfo<AbilityType>::Values[] = {
		{ AbilityType::WarriorLore, "WarriorLore" },
		{ AbilityType::RangerLore, "RangerLore" },
		{ AbilityType::RogueLore, "RogueLore" },
		{ AbilityType::SingleHanded, "SingleHanded" },
		{ AbilityType::TwoHanded, "TwoHanded" },
		{ AbilityType::PainReflection, "PainReflection" },
		{ AbilityType::Ranged, "Ranged" },
		{ AbilityType::Shield, "Shield" },
		{ AbilityType::Reflexes, "Reflexes" },
		{ AbilityType::PhysicalArmorMastery, "PhysicalArmorMastery" },
		{ AbilityType::MagicArmorMastery, "MagicArmorMastery" },
		{ AbilityType::VitalityMastery, "VitalityMastery" },
		{ AbilityType::Sourcery, "Sourcery" },
		{ AbilityType::FireSpecialist, "FireSpecialist" },
		{ AbilityType::WaterSpecialist, "WaterSpecialist" },
		{ AbilityType::AirSpecialist, "AirSpecialist" },
		{ AbilityType::EarthSpecialist, "EarthSpecialist" },
		{ AbilityType::Necromancy, "Necromancy" },
		{ AbilityType::Summoning, "Summoning" },
		{ AbilityType::Polymorph, "Polymorph" },
		{ AbilityType::Telekinesis, "Telekinesis" },
		{ AbilityType::Repair, "Repair" },
		{ AbilityType::Sneaking, "Sneaking" },
		{ AbilityType::Pickpocket, "Pickpocket" },
		{ AbilityType::Thievery, "Thievery" },
		{ AbilityType::Loremaster, "Loremaster" },
		{ AbilityType::Crafting, "Crafting" },
		{ AbilityType::Barter, "Barter" },
		{ AbilityType::Charm, "Charm" },
		{ AbilityType::Intimidate, "Intimidate" },
		{ AbilityType::Reason, "Reason" },
		{ AbilityType::Persuasion, "Persuasion" },
		{ AbilityType::Leadership, "Leadership" },
		{ AbilityType::Luck, "Luck" },
		{ AbilityType::DualWielding, "DualWielding" },
		{ AbilityType::Wand, "Wand" },
		{ AbilityType::Perseverance, "Perseverance" },
		{ AbilityType::Runecrafting, "Runecrafting" },
		{ AbilityType::Brewmaster, "Brewmaster" },
		{ AbilityType::Sulfurology, "Sulfurology" },
		{ AbilityType::Sentinel, "Sentinel" }
	};


	EnumInfo<CriticalRoll>::Label const EnumInfo<CriticalRoll>::Values[] = {
		{ CriticalRoll::Roll, "Roll" },
		{ CriticalRoll::Critical, "Critical" },
		{ CriticalRoll::NotCritical, "NotCritical" }
	};

	EnumInfo<HighGroundBonus>::Label const EnumInfo<HighGroundBonus>::Values[] = {
		{ HighGroundBonus::Unknown, "Unknown" },
		{ HighGroundBonus::HighGround, "HighGround" },
		{ HighGroundBonus::EvenGround, "EvenGround" },
		{ HighGroundBonus::LowGround, "LowGround" }
	};

	EnumInfo<StatusFlags0>::Label const EnumInfo<StatusFlags0>::Values[] = {
		{ StatusFlags0::SF0_KeepAlive, "KeepAlive" },
		{ StatusFlags0::SF0_IsOnSourceSurface, "IsOnSourceSurface" },
		{ StatusFlags0::SF0_IsFromItem, "IsFromItem" },
		{ StatusFlags0::SF0_Channeled, "Channeled" },
		{ StatusFlags0::SF0_IsLifeTimeSet, "IsLifeTimeSet" },
		{ StatusFlags0::SF0_InitiateCombat, "InitiateCombat" },
		{ StatusFlags0::SF0_Influence, "Influence" }
	};

	EnumInfo<StatusFlags1>::Label const EnumInfo<StatusFlags1>::Values[] = {
		{ StatusFlags1::SF1_BringIntoCombat, "BringIntoCombat" },
		{ StatusFlags1::SF1_IsHostileAct, "IsHostileAct" },
		{ StatusFlags1::SF1_IsInvulnerable, "IsInvulnerable" },
		{ StatusFlags1::SF1_IsResistingDeath, "IsResistingDeath" }
	};

	EnumInfo<StatusFlags2>::Label const EnumInfo<StatusFlags2>::Values[] = {
		{ StatusFlags2::SF2_ForceStatus, "ForceStatus" },
		{ StatusFlags2::SF2_ForceFailStatus, "ForceFailStatus" },
		{ StatusFlags2::SF2_RequestDelete, "RequestDelete" },
		{ StatusFlags2::SF2_RequestDeleteAtTurnEnd, "RequestDeleteAtTurnEnd" },
		{ StatusFlags2::SF2_Started, "Started" }
	};

	EnumInfo<CauseType>::Label const EnumInfo<CauseType>::Values[] = {
		{ CauseType::None, "None" },
		{ CauseType::SurfaceMove, "SurfaceMove" },
		{ CauseType::SurfaceCreate, "SurfaceCreate" },
		{ CauseType::SurfaceStatus, "SurfaceStatus" },
		{ CauseType::StatusEnter, "StatusEnter" },
		{ CauseType::StatusTick, "StatusTick" },
		{ CauseType::Attack, "Attack" },
		{ CauseType::Offhand, "Offhand" },
		{ CauseType::GM, "GM" }
	};

	EnumInfo<DeathType>::Label const EnumInfo<DeathType>::Values[] = {
		{ DeathType::None, "None" },
		{ DeathType::Physical, "Physical" },
		{ DeathType::Piercing, "Piercing" },
		{ DeathType::Arrow, "Arrow" },
		{ DeathType::DoT, "DoT" },
		{ DeathType::Incinerate, "Incinerate" },
		{ DeathType::Acid, "Acid" },
		{ DeathType::Electrocution, "Electrocution" },
		{ DeathType::FrozenShatter, "FrozenShatter" },
		{ DeathType::PetrifiedShatter, "PetrifiedShatter" },
		{ DeathType::Explode, "Explode" },
		{ DeathType::Surrender, "Surrender" },
		{ DeathType::Hang, "Hang" },
		{ DeathType::KnockedDown, "KnockedDown" },
		{ DeathType::Lifetime, "Lifetime" },
		{ DeathType::Sulfur, "Sulfur" },
		{ DeathType::Sentinel, "Sentinel" }
	};

	EnumInfo<DamageType>::Label const EnumInfo<DamageType>::Values[] = {
		{ DamageType::None, "None" },
		{ DamageType::Physical, "Physical" },
		{ DamageType::Piercing, "Piercing" },
		{ DamageType::Corrosive, "Corrosive" },
		{ DamageType::Magic, "Magic" },
		{ DamageType::Chaos, "Chaos" },
		{ DamageType::Fire, "Fire" },
		{ DamageType::Air, "Air" },
		{ DamageType::Water, "Water" },
		{ DamageType::Earth, "Earth" },
		{ DamageType::Poison, "Poison" },
		{ DamageType::Shadow, "Shadow" },
		{ DamageType::Sulfuric, "Sulfuric" },
		{ DamageType::Sentinel, "Sentinel" }
	};

	EnumInfo<HitType>::Label const EnumInfo<HitType>::Values[] = {
		{ HitType::Melee, "Melee" },
		{ HitType::Magic, "Magic" },
		{ HitType::Ranged, "Ranged" },
		{ HitType::WeaponDamage, "WeaponDamage" },
		{ HitType::Surface, "Surface" },
		{ HitType::DoT, "DoT" },
		{ HitType::Reflected, "Reflected" }
	};

	EnumInfo<ItemSlot>::Label const EnumInfo<ItemSlot>::Values[] = {
		{ ItemSlot::Helmet, "Helmet" },
		{ ItemSlot::Breast, "Breast" },
		{ ItemSlot::Leggings, "Leggings" },
		{ ItemSlot::Weapon, "Weapon" },
		{ ItemSlot::Shield, "Shield" },
		{ ItemSlot::Ring, "Ring" },
		{ ItemSlot::Belt, "Belt" },
		{ ItemSlot::Boots, "Boots" },
		{ ItemSlot::Gloves, "Gloves" },
		{ ItemSlot::Amulet, "Amulet" },
		{ ItemSlot::Ring2, "Ring2" },
		{ ItemSlot::Wings, "Wings" },
		{ ItemSlot::Horns, "Horns" },
		{ ItemSlot::Overhead, "Overhead" }
	};

	EnumInfo<EquipmentStatsType>::Label const EnumInfo<EquipmentStatsType>::Values[] = {
		{ EquipmentStatsType::Weapon, "Weapon" },
		{ EquipmentStatsType::Armor, "Armor" },
		{ EquipmentStatsType::Shield, "Shield" }
	};

	EnumInfo<HitFlag>::Label const EnumInfo<HitFlag>::Values[] = {
		{ HitFlag::HF_Hit, "Hit" },
		{ HitFlag::HF_Blocked, "Blocked" },
		{ HitFlag::HF_Dodged, "Dodged" },
		{ HitFlag::HF_Missed, "Missed" },
		{ HitFlag::HF_CriticalHit, "CriticalHit" },
		{ HitFlag::HF_AlwaysBackstab, "AlwaysBackstab" },
		{ HitFlag::HF_FromSetHP, "FromSetHP" },
		{ HitFlag::HF_DontCreateBloodSurface, "DontCreateBloodSurface" },
		{ HitFlag::HF_Reflection, "Reflection" },
		{ HitFlag::HF_NoDamageOnOwner, "NoDamageOnOwner" },
		{ HitFlag::HF_FromShacklesOfPain, "FromShacklesOfPain" },
		{ HitFlag::HF_DamagedMagicArmor, "DamagedMagicArmor" },
		{ HitFlag::HF_DamagedPhysicalArmor, "DamagedPhysicalArmor" },
		{ HitFlag::HF_DamagedVitality, "DamagedVitality" },
		{ HitFlag::HF_Flanking, "Flanking" },
		{ HitFlag::HF_PropagatedFromOwner, "PropagatedFromOwner" },
		{ HitFlag::HF_Surface, "Surface" },
		{ HitFlag::HF_DoT, "DoT" },
		{ HitFlag::HF_ProcWindWalker, "ProcWindWalker" },
		{ HitFlag::HF_CounterAttack, "CounterAttack" },
		{ HitFlag::HF_Poisoned, "Poisoned" },
		{ HitFlag::HF_Burning, "Burning" },
		{ HitFlag::HF_Bleeding, "Bleeding" },
		// Custom flags
		{ HitFlag::HF_NoEvents, "NoEvents" }
	};

	EnumInfo<StatCharacterFlags>::Label const EnumInfo<StatCharacterFlags>::Values[] = {
		{ StatCharacterFlags::SCF_IsPlayer, "IsPlayer" },
		{ StatCharacterFlags::SCF_InParty, "InParty" },
		{ StatCharacterFlags::SCF_Sneaking, "Sneaking" },
		{ StatCharacterFlags::SCF_Invisible, "Invisible" },
		{ StatCharacterFlags::SCF_Blind, "Blind" },
		{ StatCharacterFlags::SCF_DrinkedPotion, "DrinkedPotion" },
		{ StatCharacterFlags::SCF_EquipmentValidated, "EquipmentValidated" },
	};

	EnumInfo<StatusHealType>::Label const EnumInfo<StatusHealType>::Values[] = {
		{ StatusHealType::SHT_None, "None" },
		{ StatusHealType::SHT_Vitality, "Vitality" },
		{ StatusHealType::SHT_PhysicalArmor, "PhysicalArmor" },
		{ StatusHealType::SHT_MagicArmor, "MagicArmor" },
		{ StatusHealType::SHT_AllArmor, "AllArmor" },
		{ StatusHealType::SHT_All, "All" },
		{ StatusHealType::SHT_Source, "Source" }
	};

	EnumInfo<HealEffect>::Label const EnumInfo<HealEffect>::Values[] = {
		{ HealEffect::HE_None, "None" },
		{ HealEffect::HE_ResistDeath, "ResistDeath" },
		{ HealEffect::HE_Heal, "Heal" },
		{ HealEffect::HE_Behavior, "Behavior" },
		{ HealEffect::HE_Unknown4, "Unknown4" },
		{ HealEffect::HE_Sitting, "Sitting" },
		{ HealEffect::HE_Surface, "Surface" },
		{ HealEffect::HE_Lifesteal, "Lifesteal" },
		{ HealEffect::HE_NegativeDamage, "NegativeDamage" },
		{ HealEffect::HE_Unknown9, "Unknown9" },
		{ HealEffect::HE_Script, "Script" },
		{ HealEffect::HE_Necromantic, "Necromantic" },
		{ HealEffect::HE_HealSharingReflected, "HealSharingReflected" },
	};

	EnumInfo<EsvCharacterFlags>::Label const EnumInfo<EsvCharacterFlags>::Values[] = {
		{ EsvCharacterFlags::CF_IsPlayer_M, "IsPlayer" },
		{ EsvCharacterFlags::CF_IsPlayer2_M, "IsPlayer2" },
		{ EsvCharacterFlags::CF_HostControl, "HostControl" },
		{ EsvCharacterFlags::CF_OffStage, "OffStage" },
		{ EsvCharacterFlags::CF_Dead, "Dead" },
		{ EsvCharacterFlags::CF_Charmed, "Charmed" },
		{ EsvCharacterFlags::CF_InDialog, "InDialog" },
		{ EsvCharacterFlags::CF_Summon, "Summon" },
		{ EsvCharacterFlags::CF_CharacterControl, "CharacterControl" },
		{ EsvCharacterFlags::CF_Transformed_M, "Transformed" },
		{ EsvCharacterFlags::CF_InArena, "InArena" },
		{ EsvCharacterFlags::CF_Summon2, "Summon2" },
		{ EsvCharacterFlags::CF_PartyFollower, "PartyFollower" },
		{ EsvCharacterFlags::CF_Totem, "Totem" }
	};

	EnumInfo<EsvCharacterFlags2>::Label const EnumInfo<EsvCharacterFlags2>::Values[] = {
		{ EsvCharacterFlags2::CF_Global, "Global" },
		{ EsvCharacterFlags2::CF_HasOsirisDialog, "HasOsirisDialog" },
		{ EsvCharacterFlags2::CF_HasDefaultDialog, "HasDefaultDialog" },
		{ EsvCharacterFlags2::CF_TreasureGeneratedForTrader, "TreasureGeneratedForTrader" },
		{ EsvCharacterFlags2::CF_Trader, "Trader" },
		{ EsvCharacterFlags2::CF_Resurrected, "Resurrected" }
	};

	EnumInfo<EsvCharacterFlags3>::Label const EnumInfo<EsvCharacterFlags3>::Values[] = {
		{ EsvCharacterFlags3::CF_IsPet, "IsPet" },
		{ EsvCharacterFlags3::CF_IsSpectating, "IsSpectating" },
		{ EsvCharacterFlags3::CF_NoReptuationEffects, "NoReptuationEffects" },
		{ EsvCharacterFlags3::CF_HasWalkSpeedOverride, "HasWalkSpeedOverride" },
		{ EsvCharacterFlags3::CF_HasRunSpeedOverride, "HasRunSpeedOverride" },
		{ EsvCharacterFlags3::CF_IsGameMaster, "IsGameMaster" },
		{ EsvCharacterFlags3::CF_IsPossessed, "IsPossessed" }
	};

	EnumInfo<StatAttributeFlags>::Label const EnumInfo<StatAttributeFlags>::Values[] = {
		{ StatAttributeFlags::AF_FreezeImmunity, "FreezeImmunity" },
		{ StatAttributeFlags::AF_BurnImmunity, "BurnImmunity" },
		{ StatAttributeFlags::AF_StunImmunity, "StunImmunity" },
		{ StatAttributeFlags::AF_PoisonImmunity, "PoisonImmunity" },
		{ StatAttributeFlags::AF_CharmImmunity, "CharmImmunity" },
		{ StatAttributeFlags::AF_FearImmunity, "FearImmunity" },
		{ StatAttributeFlags::AF_KnockdownImmunity, "KnockdownImmunity" },
		{ StatAttributeFlags::AF_MuteImmunity, "MuteImmunity" },
		{ StatAttributeFlags::AF_ChilledImmunity, "ChilledImmunity" },
		{ StatAttributeFlags::AF_WarmImmunity, "WarmImmunity" },
		{ StatAttributeFlags::AF_WetImmunity, "WetImmunity" },
		{ StatAttributeFlags::AF_BleedingImmunity, "BleedingImmunity" },
		{ StatAttributeFlags::AF_CrippledImmunity, "CrippledImmunity" },
		{ StatAttributeFlags::AF_BlindImmunity, "BlindImmunity" },
		{ StatAttributeFlags::AF_CursedImmunity, "CursedImmunity" },
		{ StatAttributeFlags::AF_WeakImmunity, "WeakImmunity" },
		{ StatAttributeFlags::AF_SlowedImmunity, "SlowedImmunity" },
		{ StatAttributeFlags::AF_DiseasedImmunity, "DiseasedImmunity" },
		{ StatAttributeFlags::AF_InfectiousDiseasedImmunity, "InfectiousDiseasedImmunity" },
		{ StatAttributeFlags::AF_PetrifiedImmunity, "PetrifiedImmunity" },
		{ StatAttributeFlags::AF_DrunkImmunity, "DrunkImmunity" },
		{ StatAttributeFlags::AF_SlippingImmunity, "SlippingImmunity" },
		{ StatAttributeFlags::AF_FreezeContact, "FreezeContact" },
		{ StatAttributeFlags::AF_BurnContact, "BurnContact" },
		{ StatAttributeFlags::AF_StunContact, "StunContact" },
		{ StatAttributeFlags::AF_PoisonContact, "PoisonContact" },
		{ StatAttributeFlags::AF_ChillContact, "ChillContact" },
		{ StatAttributeFlags::AF_Torch, "Torch" },
		{ StatAttributeFlags::AF_Arrow, "Arrow" },
		{ StatAttributeFlags::AF_Unbreakable, "Unbreakable" },
		{ StatAttributeFlags::AF_Unrepairable, "Unrepairable" },
		{ StatAttributeFlags::AF_Unstorable, "Unstorable" },
		{ StatAttributeFlags::AF_Grounded, "Grounded" },
		{ StatAttributeFlags::AF_HastedImmunity, "HastedImmunity" },
		{ StatAttributeFlags::AF_TauntedImmunity, "TauntedImmunity" },
		{ StatAttributeFlags::AF_SleepingImmunity, "SleepingImmunity" },
		{ StatAttributeFlags::AF_AcidImmunity, "AcidImmunity" },
		{ StatAttributeFlags::AF_SuffocatingImmunity, "SuffocatingImmunity" },
		{ StatAttributeFlags::AF_RegeneratingImmunity, "RegeneratingImmunity" },
		{ StatAttributeFlags::AF_DisarmedImmunity, "DisarmedImmunity" },
		{ StatAttributeFlags::AF_DecayingImmunity, "DecayingImmunity" },
		{ StatAttributeFlags::AF_ClairvoyantImmunity, "ClairvoyantImmunity" },
		{ StatAttributeFlags::AF_EnragedImmunity, "EnragedImmunity" },
		{ StatAttributeFlags::AF_BlessedImmunity, "BlessedImmunity" },
		{ StatAttributeFlags::AF_ProtectFromSummon, "ProtectFromSummon" },
		{ StatAttributeFlags::AF_Floating, "Floating" },
		{ StatAttributeFlags::AF_DeflectProjectiles, "DeflectProjectiles" },
		{ StatAttributeFlags::AF_IgnoreClouds, "IgnoreClouds" },
		{ StatAttributeFlags::AF_MadnessImmunity, "MadnessImmunity" },
		{ StatAttributeFlags::AF_ChickenImmunity, "ChickenImmunity" },
		{ StatAttributeFlags::AF_IgnoreCursedOil, "IgnoreCursedOil" },
		{ StatAttributeFlags::AF_ShockedImmunity, "ShockedImmunity" },
		{ StatAttributeFlags::AF_WebImmunity, "WebImmunity" },
		{ StatAttributeFlags::AF_LootableWhenEquipped, "LootableWhenEquipped" },
		{ StatAttributeFlags::AF_PickpocketableWhenEquipped, "PickpocketableWhenEquipped" },
		{ StatAttributeFlags::AF_LoseDurabilityOnCharacterHit, "LoseDurabilityOnCharacterHit" },
		{ StatAttributeFlags::AF_EntangledContact, "EntangledContact" },
		{ StatAttributeFlags::AF_ShacklesOfPainImmunity, "ShacklesOfPainImmunity" },
		{ StatAttributeFlags::AF_MagicalSulfur, "MagicalSulfur" },
		{ StatAttributeFlags::AF_ThrownImmunity, "ThrownImmunity" },
		{ StatAttributeFlags::AF_InvisibilityImmunity, "InvisibilityImmunity" }
	};

	EnumInfo<TalentType>::Label const EnumInfo<TalentType>::Values[] = {
		{ TalentType::TALENT_None, "None" },
		{ TalentType::TALENT_ItemMovement, "ItemMovement" },
		{ TalentType::TALENT_ItemCreation, "ItemCreation" },
		{ TalentType::TALENT_Flanking, "Flanking" },
		{ TalentType::TALENT_AttackOfOpportunity, "AttackOfOpportunity" },
		{ TalentType::TALENT_Backstab, "Backstab" },
		{ TalentType::TALENT_Trade, "Trade" },
		{ TalentType::TALENT_Lockpick, "Lockpick" },
		{ TalentType::TALENT_ChanceToHitRanged, "ChanceToHitRanged" },
		{ TalentType::TALENT_ChanceToHitMelee, "ChanceToHitMelee" },
		{ TalentType::TALENT_Damage, "Damage" },
		{ TalentType::TALENT_ActionPoints, "ActionPoints" },
		{ TalentType::TALENT_ActionPoints2, "ActionPoints2" },
		{ TalentType::TALENT_Criticals, "Criticals" },
		{ TalentType::TALENT_IncreasedArmor, "IncreasedArmor" },
		{ TalentType::TALENT_Sight, "Sight" },
		{ TalentType::TALENT_ResistFear, "ResistFear" },
		{ TalentType::TALENT_ResistKnockdown, "ResistKnockdown" },
		{ TalentType::TALENT_ResistStun, "ResistStun" },
		{ TalentType::TALENT_ResistPoison, "ResistPoison" },
		{ TalentType::TALENT_ResistSilence, "ResistSilence" },
		{ TalentType::TALENT_ResistDead, "ResistDead" },
		{ TalentType::TALENT_Carry, "Carry" },
		{ TalentType::TALENT_Throwing, "Throwing" },
		{ TalentType::TALENT_Repair, "Repair" },
		{ TalentType::TALENT_ExpGain, "ExpGain" },
		{ TalentType::TALENT_ExtraStatPoints, "ExtraStatPoints" },
		{ TalentType::TALENT_ExtraSkillPoints, "ExtraSkillPoints" },
		{ TalentType::TALENT_Durability, "Durability" },
		{ TalentType::TALENT_Awareness, "Awareness" },
		{ TalentType::TALENT_Vitality, "Vitality" },
		{ TalentType::TALENT_FireSpells, "FireSpells" },
		{ TalentType::TALENT_WaterSpells, "WaterSpells" },
		{ TalentType::TALENT_AirSpells, "AirSpells" },
		{ TalentType::TALENT_EarthSpells, "EarthSpells" },
		{ TalentType::TALENT_Charm, "Charm" },
		{ TalentType::TALENT_Intimidate, "Intimidate" },
		{ TalentType::TALENT_Reason, "Reason" },
		{ TalentType::TALENT_Luck, "Luck" },
		{ TalentType::TALENT_Initiative, "Initiative" },
		{ TalentType::TALENT_InventoryAccess, "InventoryAccess" },
		{ TalentType::TALENT_AvoidDetection, "AvoidDetection" },
		{ TalentType::TALENT_AnimalEmpathy, "AnimalEmpathy" },
		{ TalentType::TALENT_Escapist, "Escapist" },
		{ TalentType::TALENT_StandYourGround, "StandYourGround" },
		{ TalentType::TALENT_SurpriseAttack, "SurpriseAttack" },
		{ TalentType::TALENT_LightStep, "LightStep" },
		{ TalentType::TALENT_ResurrectToFullHealth, "ResurrectToFullHealth" },
		{ TalentType::TALENT_Scientist, "Scientist" },
		{ TalentType::TALENT_Raistlin, "Raistlin" },
		{ TalentType::TALENT_MrKnowItAll, "MrKnowItAll" },
		{ TalentType::TALENT_WhatARush, "WhatARush" },
		{ TalentType::TALENT_FaroutDude, "FaroutDude" },
		{ TalentType::TALENT_Leech, "Leech" },
		{ TalentType::TALENT_ElementalAffinity, "ElementalAffinity" },
		{ TalentType::TALENT_FiveStarRestaurant, "FiveStarRestaurant" },
		{ TalentType::TALENT_Bully, "Bully" },
		{ TalentType::TALENT_ElementalRanger, "ElementalRanger" },
		{ TalentType::TALENT_LightningRod, "LightningRod" },
		{ TalentType::TALENT_Politician, "Politician" },
		{ TalentType::TALENT_WeatherProof, "WeatherProof" },
		{ TalentType::TALENT_LoneWolf, "LoneWolf" },
		{ TalentType::TALENT_Zombie, "Zombie" },
		{ TalentType::TALENT_Demon, "Demon" },
		{ TalentType::TALENT_IceKing, "IceKing" },
		{ TalentType::TALENT_Courageous, "Courageous" },
		{ TalentType::TALENT_GoldenMage, "GoldenMage" },
		{ TalentType::TALENT_WalkItOff, "WalkItOff" },
		{ TalentType::TALENT_FolkDancer, "FolkDancer" },
		{ TalentType::TALENT_SpillNoBlood, "SpillNoBlood" },
		{ TalentType::TALENT_Stench, "Stench" },
		{ TalentType::TALENT_Kickstarter, "Kickstarter" },
		{ TalentType::TALENT_WarriorLoreNaturalArmor, "WarriorLoreNaturalArmor" },
		{ TalentType::TALENT_WarriorLoreNaturalHealth, "WarriorLoreNaturalHealth" },
		{ TalentType::TALENT_WarriorLoreNaturalResistance, "WarriorLoreNaturalResistance" },
		{ TalentType::TALENT_RangerLoreArrowRecover, "RangerLoreArrowRecover" },
		{ TalentType::TALENT_RangerLoreEvasionBonus, "RangerLoreEvasionBonus" },
		{ TalentType::TALENT_RangerLoreRangedAPBonus, "RangerLoreRangedAPBonus" },
		{ TalentType::TALENT_RogueLoreDaggerAPBonus, "RogueLoreDaggerAPBonus" },
		{ TalentType::TALENT_RogueLoreDaggerBackStab, "RogueLoreDaggerBackStab" },
		{ TalentType::TALENT_RogueLoreMovementBonus, "RogueLoreMovementBonus" },
		{ TalentType::TALENT_RogueLoreHoldResistance, "RogueLoreHoldResistance" },
		{ TalentType::TALENT_NoAttackOfOpportunity, "NoAttackOfOpportunity" },
		{ TalentType::TALENT_WarriorLoreGrenadeRange, "WarriorLoreGrenadeRange" },
		{ TalentType::TALENT_RogueLoreGrenadePrecision, "RogueLoreGrenadePrecision" },
		{ TalentType::TALENT_WandCharge, "WandCharge" },
		{ TalentType::TALENT_DualWieldingDodging, "DualWieldingDodging" },
		{ TalentType::TALENT_Human_Inventive, "Human_Inventive" },
		{ TalentType::TALENT_Human_Civil, "Human_Civil" },
		{ TalentType::TALENT_Elf_Lore, "Elf_Lore" },
		{ TalentType::TALENT_Elf_CorpseEating, "Elf_CorpseEating" },
		{ TalentType::TALENT_Dwarf_Sturdy, "Dwarf_Sturdy" },
		{ TalentType::TALENT_Dwarf_Sneaking, "Dwarf_Sneaking" },
		{ TalentType::TALENT_Lizard_Resistance, "Lizard_Resistance" },
		{ TalentType::TALENT_Lizard_Persuasion, "Lizard_Persuasion" },
		{ TalentType::TALENT_Perfectionist, "Perfectionist" },
		{ TalentType::TALENT_Executioner, "Executioner" },
		{ TalentType::TALENT_ViolentMagic, "ViolentMagic" },
		{ TalentType::TALENT_QuickStep, "QuickStep" },
		{ TalentType::TALENT_Quest_SpidersKiss_Str, "Quest_SpidersKiss_Str" },
		{ TalentType::TALENT_Quest_SpidersKiss_Int, "Quest_SpidersKiss_Int" },
		{ TalentType::TALENT_Quest_SpidersKiss_Per, "Quest_SpidersKiss_Per" },
		{ TalentType::TALENT_Quest_SpidersKiss_Null, "Quest_SpidersKiss_Null" },
		{ TalentType::TALENT_Memory, "Memory" },
		{ TalentType::TALENT_Quest_TradeSecrets, "Quest_TradeSecrets" },
		{ TalentType::TALENT_Quest_GhostTree, "Quest_GhostTree" },
		{ TalentType::TALENT_BeastMaster, "BeastMaster" },
		{ TalentType::TALENT_LivingArmor, "LivingArmor" },
		{ TalentType::TALENT_Torturer, "Torturer" },
		{ TalentType::TALENT_Ambidextrous, "Ambidextrous" },
		{ TalentType::TALENT_Unstable, "Unstable" },
		{ TalentType::TALENT_ResurrectExtraHealth, "ResurrectExtraHealth" },
		{ TalentType::TALENT_NaturalConductor, "NaturalConductor" },
		{ TalentType::TALENT_Quest_Rooted, "Quest_Rooted" },
		{ TalentType::TALENT_PainDrinker, "PainDrinker" },
		{ TalentType::TALENT_DeathfogResistant, "DeathfogResistant" },
		{ TalentType::TALENT_Sourcerer, "Sourcerer" },
		{ TalentType::TALENT_Rager, "Rager" },
		{ TalentType::TALENT_Elementalist, "Elementalist" },
		{ TalentType::TALENT_Sadist, "Sadist" },
		{ TalentType::TALENT_Haymaker, "Haymaker" },
		{ TalentType::TALENT_Gladiator, "Gladiator" },
		{ TalentType::TALENT_Indomitable, "Indomitable" },
		{ TalentType::TALENT_WildMag, "WildMag" },
		{ TalentType::TALENT_Jitterbug, "Jitterbug" },
		{ TalentType::TALENT_Soulcatcher, "Soulcatcher" },
		{ TalentType::TALENT_MasterThief, "MasterThief" },
		{ TalentType::TALENT_GreedyVessel, "GreedyVessel" },
		{ TalentType::TALENT_MagicCycles, "MagicCycles" }
	};

}
