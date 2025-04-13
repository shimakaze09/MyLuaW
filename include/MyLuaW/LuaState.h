#pragma once

#include "LuaStateView.h"

#include <memory>

namespace My {
class LuaState {
 public:
  //
  // Constructor
  ////////////////

  LuaState();
  LuaState(lua_Alloc f, void* userdata);
  LuaState(std::shared_ptr<lua_State> main, LuaStateView L);

  std::shared_ptr<lua_State> GetSharedMainState() { return main; }

  lua_State* GetState() { return L.GetState(); }

  lua_State* GetMainState() { return main.get(); }

  LuaStateView View() { return L; }

  LuaStateView MainView() { return main.get(); }

  operator LuaStateView() { return L; }

  LuaStateView operator->() { return L; }

  LuaState newthread();

 private:
  std::shared_ptr<lua_State> main;
  LuaStateView L;
};
}  // namespace My
