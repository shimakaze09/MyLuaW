#pragma once

#include <lua.hpp>

#include <memory>

namespace My {
class LuaState {
 public:
  //
  // Constructor
  ////////////////

  struct InitConfig {
    // lua_newstate
    lua_Alloc alloc;
    void* alloc_ud;
  };

  LuaState();
  LuaState(lua_Alloc f, void* userdata);
  LuaState(std::shared_ptr<lua_State> L);

  //
  // C API
  //////////

  // Calls a function in protected mode.
  int pcall(int nargs, int nresults, int msgh);

  // Pops n elements from the stack.
  void pop(int n);

  // Converts the Lua value at the given index to a C string.
  const char* tostring(int index);

  //
  // Auxiliary Library
  //////////////////////

  // Loads a string as a Lua chunk.
  int loadstring(const char* s);

  // Opens all standard Lua libraries.
  void openlibs();

 private:
  std::shared_ptr<lua_State> L;
};
}  // namespace My
