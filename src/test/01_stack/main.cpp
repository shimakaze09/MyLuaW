#include <MyLuaW/MyLuaW.h>

#include <iostream>

using namespace My;

static void stackDump(LuaState L) {
  int i;
  int top = L.gettop();        /* depth of the stack */
  for (i = 1; i <= top; i++) { /* repeat for each level */
    int t = L.type(i);
    ;
    switch (t) {
      case LUA_TSTRING: { /* strings */
        printf("'%s'", L.tostring(i));
        break;
      }
      case LUA_TBOOLEAN: { /* Booleans */
        printf(L.toboolean(i) ? "true" : "false");
        break;
      }
      case LUA_TNUMBER: { /* numbers */
        printf("%g", L.tonumber(i));
        break;
      }
      default: { /* other values */
        printf("%s", L.typename_(t));
        break;
      }
    }
    printf(" "); /* put a separator */
  }
  printf("\n"); /* end the listing */
}

int main() {
  LuaState L;

  L.pushboolean(1);
  L.pushnumber(10);
  L.pushnil();
  L.pushstring("hello");

  stackDump(L); /* will print: true 10 nil 'hello' */
  L.pushvalue(-4);
  stackDump(L); /* will print: true 10 nil 'hello' true */
  L.replace(3);
  stackDump(L); /* will print: true 10 true 'hello' */
  L.settop(6);
  stackDump(L); /* will print: true 10 true 'hello' nil nil */
  L.rotate(3, 1);
  stackDump(L); /* will print: true 10 nil true 'hello' nil */
  L.remove(-3);
  stackDump(L); /* will print: true 10 nil 'hello' nil */
  L.settop(-5);
  stackDump(L); /* will print: true */

  return 0;
}
