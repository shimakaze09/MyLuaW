#pragma once

#include <lua.hpp>

namespace My {
class LuaStateView {
 public:
  LuaStateView() noexcept : L{nullptr} {}

  LuaStateView(lua_State* L) noexcept : L{L} {}

  lua_State* GetState() { return L; }

  bool Valid() const { return L != nullptr; }

  operator lua_State*() { return L; }

  int absindex(int idx);
  void arith(int op);
  lua_CFunction atpanic(lua_CFunction panicf);
  void call(int nargs, int nresults);
  void callk(int nargs, int nresults, lua_KContext ctx, lua_KFunction k);
  int checkstack(int n);
  int compare(int index1, int index2, int op);
  void concat(int n);
  void copy(int fromidx, int toidx);
  void createtable(int narr, int nrec);
  int dump(lua_Writer writer, void* data, int strip);
  int error();
  int gc(int what, int data);
  lua_Alloc getallocf(void** ud);
  int getfield(int index, const char* k);
  void* getextraspace();
  int getglobal(const char* name);
  lua_Hook gethook();
  int gethookcount();
  int gethookmask();
  int geti(int index, lua_Integer i);
  int getinfo(const char* what, lua_Debug* ar);
  const char* getlocal(const lua_Debug* ar, int n);
  int getmetatable(int index);
  int getstack(int level, lua_Debug* ar);
  int gettable(int index);
  int gettop();
  const char* getupvalue(int funcindex, int n);
  int getuservalue(int index);
  void insert(int index);
  int isboolean(int index);
  int iscfunction(int index);
  int isfunction(int index);
  int isinteger(int index);
  int islightuserdata(int index);
  int isnil(int index);
  int isnone(int index);
  int isnoneornil(int index);
  int isnumber(int index);
  int isstring(int index);
  int istable(int index);
  int isthread(int index);
  int isuserdata(int index);
  int isyieldable();
  void len(int index);
  int load(lua_Reader reader, void* data, const char* chunkname,
           const char* mode);
  void newtable();
  void* newuserdata(size_t size);
  int next(int index);
  int pcall(int nargs, int nresults, int msgh);
  int pcallk(int nargs, int nresults, int msgh, lua_KContext ctx,
             lua_KFunction k);
  void pop(int n);
  void pushboolean(int b);
  void pushcclosure(lua_CFunction fn, int n);
  void pushcfunction(lua_CFunction f);
  const char* pushfstring(const char* fmt, ...);
  int pushglobaltable();
  void pushinteger(lua_Integer n);
  void pushlightuserdata(void* p);
  const char* pushlstring(const char* s, size_t len);
  void pushnil();
  void pushnumber(lua_Number n);
  const char* pushstring(const char* s);
  int pushthread();
  void pushvalue(int index);
  const char* pushvfstring(const char* fmt, va_list argp);
  int rawequal(int index1, int index2);
  int rawget(int index);
  int rawgeti(int index, lua_Integer n);
  int rawgetp(int index, const void* p);
  size_t rawlen(int index);
  void rawset(int index);
  void rawseti(int index, lua_Integer i);
  void rawsetp(int index, const void* p);
  void register_(const char* name, lua_CFunction f);
  void remove(int index);
  void replace(int index);
  int resume(lua_State* from, int nargs);
  void rotate(int idx, int n);
  void setallocf(lua_Alloc f, void* ud);
  void setfield(int index, const char* k);
  void setglobal(const char* name);
  void seti(int index, lua_Integer n);
  int setmetatable(int index);
  void settable(int index);
  void settop(int index);
  void setuservalue(int index);
  int status();
  size_t stringtonumber(const char* s);
  int toboolean(int index);
  lua_CFunction tocfunction(int index);
  lua_Integer tointeger(int index);
  lua_Integer tointegerx(int index, int* isnum);
  const char* tolstring(int index, size_t* len);
  lua_Number tonumber(int index);
  lua_Number tonumberx(int index, int* isnum);
  const void* topointer(int index);
  const char* tostring(int index);
  void* touserdata(int index);
  int type(int index);
  const char* typename_(int tp);
  const lua_Number* version();
  void xmove(lua_State* from, lua_State* to, int n);
  int yield(int nresults);
  int yieldk(int nresults, lua_KContext ctx, lua_KFunction k);
  void sethook(lua_Hook f, int mask, int count);
  const char* setlocal(const lua_Debug* ar, int n);
  const char* setupvalue(int funcindex, int n);
  void* upvalueid(int funcindex, int n);
  void upvaluejoin(int funcindex1, int n1, int funcindex2, int n2);
  void argcheck(int cond, int arg, const char* extramsg);
  int argerror(int arg, const char* extramsg);
  void buffinit(luaL_Buffer* B);
  char* buffinitsize(luaL_Buffer* B, size_t sz);
  int callmeta(int obj, const char* e);
  void checkany(int arg);
  lua_Integer checkinteger(int arg);
  const char* checklstring(int arg, size_t* l);
  lua_Number checknumber(int arg);
  int checkoption(int arg, const char* def, const char* const lst[]);
  void checkstack(int sz, const char* msg);
  const char* checkstring(int arg);
  void checktype(int arg, int t);
  void* checkudata(int arg, const char* tname);
  void checkversion();
  int dofile(const char* filename);
  int dostring(const char* str);
  int error(const char* fmt, ...);
  int execresult(int stat);
  int fileresult(int stat, const char* fname);
  int getmetafield(int obj, const char* e);
  int getmetatable(const char* tname);
  int getsubtable(int idx, const char* fname);
  const char* gsub(const char* s, const char* p, const char* r);
  lua_Integer lenL(int index);
  int loadbuffer(const char* buff, size_t sz, const char* name);
  int loadbufferx(const char* buff, size_t sz, const char* name,
                  const char* mode);
  int loadfile(const char* filename);
  int loadfilex(const char* filename, const char* mode);
  int loadstring(const char* s);
  void newlib(const luaL_Reg l[]);
  void newlibtable(const luaL_Reg l[]);
  int newmetatable(const char* tname);
  void openlibs();
  lua_Integer optinteger(int arg, lua_Integer d);
  const char* optlstring(int arg, const char* d, size_t* l);
  lua_Number optnumber(int arg, lua_Number d);
  const char* optstring(int arg, const char* d);
  int ref(int t);
  void requiref(const char* modname, lua_CFunction openf, int glb);
  void setfuncs(const luaL_Reg* l, int nup);
  void setmetatable(const char* tname);
  void* testudata(int arg, const char* tname);
  const char* tolstringL(int idx, size_t* len);
  const char* typenameL(int tp);
  void unref(int t, int ref);
  void where(int lvl);

 protected:
  lua_State* L;
};
}  // namespace My
