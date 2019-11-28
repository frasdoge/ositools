#pragma once

#include <CustomFunctions.h>
#include <OsirisHelpers.h>

#include <cstdint>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <mutex>

namespace osidbg
{
	void LuaToOsi(lua_State * L, int i, TypedValue & tv, ValueType osiType);
	TypedValue * LuaToOsi(lua_State * L, int i, ValueType osiType);
	void LuaToOsi(lua_State * L, int i, OsiArgumentValue & arg, ValueType osiType);
	void OsiToLua(lua_State * L, OsiArgumentValue const & arg);
	void OsiToLua(lua_State * L, TypedValue const & tv);

	class LuaCallable {};

	template <class T>
	class LuaUserdata
	{
	public:
		static T * FromUserData(lua_State * L, int index)
		{
			luaL_checktype(L, index, LUA_TUSERDATA);
			auto obj = reinterpret_cast<T *>(luaL_checkudata(L, index, T::MetatableName));
			if (obj == nullptr) luaL_error(L, "Metatable type mismatch");
			return obj;
		}

		template <class... Args>
		static T * New(lua_State * L, Args... args)
		{
			auto obj = reinterpret_cast<T *>(lua_newuserdata(L, sizeof(T)));
			new (obj) T(std::forward<Args>(args)...);
			luaL_setmetatable(L, T::MetatableName);
			return obj;
		}

		static int LuaCallProxy(lua_State * L)
		{
			if constexpr (std::is_base_of_v<LuaCallable, T>) {
				auto self = FromUserData(L, 1);
				return self->LuaCall(L);
			} else {
				luaL_error(L, "Not callable!");
				return 0;
			}
		}

		static void RegisterMetatable(lua_State * L)
		{
			lua_register(L, T::MetatableName, nullptr);
			luaL_newmetatable(L, T::MetatableName); // stack: mt

			if constexpr (std::is_base_of_v<LuaCallable, T>) {
				lua_pushcfunction(L, &LuaCallProxy); // stack: mt, &LuaCall
				lua_setfield(L, -2, "__call"); // mt.__call = &LuaCall; stack: mt
			}

			lua_pop(L, 1); // stack: -
		}
	};

	class LuaOsiFunction
	{
	public:
		inline bool IsBound() const
		{
			return function_ != nullptr;
		}

		bool Bind(Function const * func, class LuaState & state);
		void Unbind();

		int LuaCall(lua_State * L);

	private:
		Function const * function_{ nullptr };
		AdapterRef adapter_;
		LuaState * state_;

		void OsiCall(lua_State * L);
		void OsiInsert(lua_State * L, bool deleteTuple);
		int OsiQuery(lua_State * L);
		int OsiUserQuery(lua_State * L);
	};

	class LuaOsiFunctionNameProxy : public LuaUserdata<LuaOsiFunctionNameProxy>, public LuaCallable
	{
	public:
		static char const * const MetatableName;
		// Maximum number of OUT params that a query can return.
		// (This setting determines how many function arities we'll check during name lookup)
		static constexpr uint32_t MaxQueryOutParams = 6;

		LuaOsiFunctionNameProxy(std::string const & name, LuaState & state);

		void UnbindAll();
		int LuaCall(lua_State * L);

	private:
		std::string name_;
		std::vector<LuaOsiFunction> functions_;
		LuaState & state_;
		uint32_t generationId_;

		LuaOsiFunction * TryGetFunction(uint32_t arity);
		LuaOsiFunction * CreateFunctionMapping(uint32_t arity, Function const * func);
		Function const * LookupOsiFunction(uint32_t arity);
	};


	class OsiProxyLibrary
	{
	public:
		OsiProxyLibrary();

		void Register(lua_State * L);
		void RegisterLib(lua_State * L);
		std::string GenerateOsiHelpers();

	private:
		static char const * const NameResolverMetatableName;

		void RegisterNameResolverMetatable(lua_State * L);
		void CreateNameResolver(lua_State * L);

		static int LuaIndexResolverTable(lua_State * L);

		static int Require(lua_State * L);
	};

	inline void OsiReleaseArgument(OsiArgumentDesc & arg)
	{
		arg.NextParam = nullptr;
	}

	inline void OsiReleaseArgument(TypedValue & arg) {}
	inline void OsiReleaseArgument(ListNode<TypedValue *> & arg) {}
	inline void OsiReleaseArgument(ListNode<TupleLL::Item> & arg) {}

	template <class T>
	class OsiArgumentPool
	{
	public:
		OsiArgumentPool()
		{
			argumentPool_.resize(1024);
			usedArguments_ = 0;
		}

		T * AllocateArguments(uint32_t num, uint32_t & tail)
		{
			if (usedArguments_ + num > argumentPool_.size()) {
				throw std::runtime_error("Ran out of argument descriptors");
			}

			tail = usedArguments_;
			auto ptr = argumentPool_.data() + usedArguments_;
			for (uint32_t i = 0; i < num; i++) {
				new (ptr + i) T();
			}

			usedArguments_ += num;
			return ptr;
		}

		void ReleaseArguments(uint32_t tail, uint32_t num)
		{
			if (tail + num != usedArguments_) {
				throw std::runtime_error("Attempted to release arguments out of order");
			}

			for (uint32_t i = 0; i < num; i++) {
				OsiReleaseArgument(argumentPool_[tail + i]);
			}

			usedArguments_ -= num;
		}

	private:
		std::vector<T> argumentPool_;
		uint32_t usedArguments_;
	};

	template <class T>
	class OsiArgumentListPin
	{
	public:
		inline OsiArgumentListPin(OsiArgumentPool<T> & pool, uint32_t numArgs)
			: pool_(pool), numArgs_(numArgs)
		{
			args_ = pool.AllocateArguments(numArgs_, tail_);
		}

		inline ~OsiArgumentListPin()
		{
			pool_.ReleaseArguments(tail_, numArgs_);
		}

		inline T * Args() const
		{
			return args_;
		}

	private:
		OsiArgumentPool<T> & pool_;
		uint32_t numArgs_;
		uint32_t tail_;
		T * args_;
	};

	class LuaState
	{
	public:
		LuaState();
		~LuaState();

		LuaState(LuaState const &) = delete;
		LuaState(LuaState &&) = delete;
		LuaState & operator = (LuaState const &) = delete;
		LuaState & operator = (LuaState &&) = delete;

		inline lua_State * State()
		{
			return state_;
		}

		inline uint32_t GenerationId() const
		{
			return generationId_;
		}

		inline IdentityAdapterMap & GetIdentityAdapterMap()
		{
			return identityAdapters_;
		}

		inline OsiArgumentPool<OsiArgumentDesc> & GetArgumentDescPool()
		{
			return argDescPool_;
		}

		inline OsiArgumentPool<TypedValue> & GetTypedValuePool()
		{
			return tvPool_;
		}

		inline OsiArgumentPool<ListNode<TypedValue *>> & GetTypedValueNodePool()
		{
			return tvNodePool_;
		}

		inline OsiArgumentPool<ListNode<TupleLL::Item>> & GetTupleNodePool()
		{
			return tupleNodePool_;
		}

		void OpenLibs();
		void StoryLoaded();
		void StoryFunctionMappingsUpdated();

		bool LoadScript(std::string const & script, std::string const & name = "");

		template <class TArg>
		void Call(char const * func, std::vector<TArg> const & args)
		{
			std::lock_guard lock(mutex_);

			auto L = state_;

			lua_getglobal(L, func); // stack: func
			for (auto & arg : args) {
				OsiToLua(L, arg); // stack: func, arg0 ... argn
			}
			
			auto status = lua_pcall(L, (int)args.size(), 0, 0);
			if (status != LUA_OK) {
				OsiError("Failed to call function '" << func << "': " << lua_tostring(L, -1));
				// stack: errmsg
				lua_pop(L, 1); // stack: -
			}
		}

	private:
		lua_State * state_;
		OsiProxyLibrary proxy_;
		OsiArgumentPool<OsiArgumentDesc> argDescPool_;
		OsiArgumentPool<TypedValue> tvPool_;
		OsiArgumentPool<ListNode<TypedValue *>> tvNodePool_;
		OsiArgumentPool<ListNode<TupleLL::Item>> tupleNodePool_;
		IdentityAdapterMap identityAdapters_;
		std::recursive_mutex mutex_;
		// ID of current story instance.
		// Used to invalidate function/node pointers in Lua userdata objects
		uint32_t generationId_{ 0 };
	};
}
