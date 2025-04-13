#include <MyLuaW/LuaState.h>

using namespace My;

LuaState::LuaState() : L{luaL_newstate(), lua_close} {}

LuaState::LuaState(lua_Alloc f, void* userdata)
    : L{lua_newstate(f, userdata), lua_close} {}

LuaState::LuaState(std::shared_ptr<lua_State> L) : L{std::move(L)} {}

//
// C-API
//////////

int LuaState::pcall(int nargs, int nresults, int msgh) {
  return lua_pcall(L.get(), nargs, nresults, msgh);
}

void LuaState::pop(int n) {
  lua_pop(L.get(), n);
}

const char* LuaState::tostring(int index) {
  return lua_tostring(L.get(), index);
}

//
// Auxiliary Library
//////////////////////

int LuaState::loadstring(const char* s) {
  return luaL_loadstring(L.get(), s);
}

void LuaState::openlibs() {
  luaL_openlibs(L.get());
}
