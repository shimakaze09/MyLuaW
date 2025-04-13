#pragma once

#include "LuaStateView.h"

namespace My {
class LuaRef {
 public:
  LuaRef(LuaStateView L, int t) : L{L}, t{t} { ref = L.ref(t); }

  LuaRef(LuaStateView L) : LuaRef{L, LUA_REGISTRYINDEX} {}

  bool IsNil() const noexcept { return ref == LUA_REFNIL; }

  int Get() { return L.rawgeti(t, ref); }

  ~LuaRef() {
    if (IsNil())
      return;
    L.unref(t, ref);
  }

 private:
  LuaStateView L;
  int t;
  int ref;
};
}  // namespace My
