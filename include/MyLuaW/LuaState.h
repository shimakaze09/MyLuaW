#pragma once

#include "LuaStateView.h"

#include <memory>

namespace My {
class LuaState : public LuaStateView {
 public:
  //
  // Constructor
  ////////////////

  LuaState();
  LuaState(lua_Alloc f, void* userdata);
  LuaState(std::shared_ptr<lua_State> main, LuaStateView L);

  std::shared_ptr<lua_State> GetSharedMainState() { return main; }

  lua_State* GetMainState() { return main.get(); }

  LuaStateView MainView() { return main.get(); }

  LuaState newthread();

 private:
  std::shared_ptr<lua_State> main;
};
}  // namespace My
