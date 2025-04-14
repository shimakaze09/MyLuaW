#pragma once

#include "LuaStateView.h"

namespace My {
class LuaRef {
 public:
  LuaRef() noexcept : t{0}, ref{LUA_REFNIL} {}

  LuaRef(LuaStateView L, int t) : L{L}, t{t} { ref = L.ref(t); }

  LuaRef(LuaStateView L) : LuaRef{L, LUA_REGISTRYINDEX} {}

  LuaStateView GetView() const noexcept { return L; }

  bool IsNil() const noexcept { return ref == LUA_REFNIL; }

  int Get() { return L.rawgeti(t, ref); }

  ~LuaRef() {
    if (IsNil())
      return;
    L.unref(t, ref);
  }

  LuaRef(LuaRef&& rhs) noexcept : L{rhs.L}, t{rhs.t}, ref{rhs.ref} {
    rhs.L = LuaStateView{};
    rhs.t = 0;
    rhs.ref = LUA_REFNIL;
  }

  LuaRef(const LuaRef&) = delete;
  LuaRef& operator=(const LuaRef&) = delete;

  LuaRef& operator=(LuaRef&& rhs) noexcept {
    std::swap(L, rhs.L);
    std::swap(t, rhs.t);
    std::swap(ref, rhs.ref);
    return *this;
  }

 private:
  LuaStateView L;
  int t;
  int ref;
};
}  // namespace My
