#include <MyLuaW/LuaState.h>

using namespace My;

LuaState::LuaState(std::shared_ptr<lua_State> main, LuaStateView L)
    : main{std::move(main)}, L{L} {}

LuaState::LuaState() : main{luaL_newstate(), lua_close}, L{main.get()} {}

LuaState::LuaState(lua_Alloc f, void* userdata)
    : main{lua_newstate(f, userdata), lua_close}, L{main.get()} {}

LuaState LuaState::newthread() {
  return {main, lua_newthread(L)};
}
