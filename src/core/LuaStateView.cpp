#include <MyLuaW/LuaStateView.h>

using namespace My;

int LuaStateView::absindex(int idx) {
  return lua_absindex(L, idx);
}

void LuaStateView::arith(int op) {
  return lua_arith(L, op);
}

lua_CFunction LuaStateView::atpanic(lua_CFunction panicf) {
  return lua_atpanic(L, panicf);
}

void LuaStateView::call(int nargs, int nresults) {
  return lua_call(L, nargs, nresults);
}

void LuaStateView::callk(int nargs, int nresults, lua_KContext ctx,
                         lua_KFunction k) {
  return lua_callk(L, nargs, nresults, ctx, k);
}

int LuaStateView::checkstack(int n) {
  return lua_checkstack(L, n);
}

int LuaStateView::compare(int index1, int index2, int op) {
  return lua_compare(L, index1, index2, op);
}

void LuaStateView::concat(int n) {
  return lua_concat(L, n);
}

void LuaStateView::copy(int fromidx, int toidx) {
  return lua_copy(L, fromidx, toidx);
}

void LuaStateView::createtable(int narr, int nrec) {
  return lua_createtable(L, narr, nrec);
}

int LuaStateView::dump(lua_Writer writer, void* data, int strip) {
  return lua_dump(L, writer, data, strip);
}

int LuaStateView::error() {
  return lua_error(L);
}

int LuaStateView::gc(int what, int data) {
  return lua_gc(L, what, data);
}

lua_Alloc LuaStateView::getallocf(void** ud) {
  return lua_getallocf(L, ud);
}

int LuaStateView::getfield(int index, const char* k) {
  return lua_getfield(L, index, k);
}

void* LuaStateView::getextraspace() {
  return lua_getextraspace(L);
}

int LuaStateView::getglobal(const char* name) {
  return lua_getglobal(L, name);
}

lua_Hook LuaStateView::gethook() {
  return lua_gethook(L);
}

int LuaStateView::gethookcount() {
  return lua_gethookcount(L);
}

int LuaStateView::gethookmask() {
  return lua_gethookmask(L);
}

int LuaStateView::geti(int index, lua_Integer i) {
  return lua_geti(L, index, i);
}

int LuaStateView::getinfo(const char* what, lua_Debug* ar) {
  return lua_getinfo(L, what, ar);
}

const char* LuaStateView::getlocal(const lua_Debug* ar, int n) {
  return lua_getlocal(L, ar, n);
}

int LuaStateView::getmetatable(int index) {
  return lua_getmetatable(L, index);
}

int LuaStateView::getstack(int level, lua_Debug* ar) {
  return lua_getstack(L, level, ar);
}

int LuaStateView::gettable(int index) {
  return lua_gettable(L, index);
}

int LuaStateView::gettop() {
  return lua_gettop(L);
}

const char* LuaStateView::getupvalue(int funcindex, int n) {
  return lua_getupvalue(L, funcindex, n);
}

int LuaStateView::getuservalue(int index) {
  return lua_getuservalue(L, index);
}

void LuaStateView::insert(int index) {
  return lua_insert(L, index);
}

int LuaStateView::isboolean(int index) {
  return lua_isboolean(L, index);
}

int LuaStateView::iscfunction(int index) {
  return lua_iscfunction(L, index);
}

int LuaStateView::isfunction(int index) {
  return lua_isfunction(L, index);
}

int LuaStateView::isinteger(int index) {
  return lua_isinteger(L, index);
}

int LuaStateView::islightuserdata(int index) {
  return lua_islightuserdata(L, index);
}

int LuaStateView::isnil(int index) {
  return lua_isnil(L, index);
}

int LuaStateView::isnone(int index) {
  return lua_isnone(L, index);
}

int LuaStateView::isnoneornil(int index) {
  return lua_isnoneornil(L, index);
}

int LuaStateView::isnumber(int index) {
  return lua_isnumber(L, index);
}

int LuaStateView::isstring(int index) {
  return lua_isstring(L, index);
}

int LuaStateView::istable(int index) {
  return lua_istable(L, index);
}

int LuaStateView::isthread(int index) {
  return lua_isthread(L, index);
}

int LuaStateView::isuserdata(int index) {
  return lua_isuserdata(L, index);
}

int LuaStateView::isyieldable() {
  return lua_isyieldable(L);
}

void LuaStateView::len(int index) {
  return lua_len(L, index);
}

int LuaStateView::load(lua_Reader reader, void* data, const char* chunkname,
                       const char* mode) {
  return lua_load(L, reader, data, chunkname, mode);
}

void LuaStateView::newtable() {
  return lua_newtable(L);
}

void* LuaStateView::newuserdata(size_t size) {
  return lua_newuserdata(L, size);
}

int LuaStateView::next(int index) {
  return lua_next(L, index);
}

int LuaStateView::pcall(int nargs, int nresults, int msgh) {
  return lua_pcall(L, nargs, nresults, msgh);
}

int LuaStateView::pcallk(int nargs, int nresults, int msgh, lua_KContext ctx,
                         lua_KFunction k) {
  return lua_pcallk(L, nargs, nresults, msgh, ctx, k);
}

void LuaStateView::pop(int n) {
  return lua_pop(L, n);
}

void LuaStateView::pushboolean(int b) {
  return lua_pushboolean(L, b);
}

void LuaStateView::pushcclosure(lua_CFunction fn, int n) {
  return lua_pushcclosure(L, fn, n);
}

void LuaStateView::pushcfunction(lua_CFunction f) {
  return lua_pushcfunction(L, f);
}

const char* LuaStateView::pushfstring(const char* fmt, ...) {
  va_list argp;
  va_start(argp, fmt);
  const char* rst = pushvfstring(fmt, argp);
  va_end(argp);
  return rst;
}

int LuaStateView::pushglobaltable() {
  return lua_pushglobaltable(L);
}

void LuaStateView::pushinteger(lua_Integer n) {
  return lua_pushinteger(L, n);
}

void LuaStateView::pushlightuserdata(void* p) {
  return lua_pushlightuserdata(L, p);
}

const char* LuaStateView::pushlstring(const char* s, size_t len) {
  return lua_pushlstring(L, s, len);
}

void LuaStateView::pushnil() {
  return lua_pushnil(L);
}

void LuaStateView::pushnumber(lua_Number n) {
  return lua_pushnumber(L, n);
}

const char* LuaStateView::pushstring(const char* s) {
  return lua_pushstring(L, s);
}

int LuaStateView::pushthread() {
  return lua_pushthread(L);
}

void LuaStateView::pushvalue(int index) {
  return lua_pushvalue(L, index);
}

const char* LuaStateView::pushvfstring(const char* fmt, va_list argp) {
  return lua_pushvfstring(L, fmt, argp);
}

int LuaStateView::rawequal(int index1, int index2) {
  return lua_rawequal(L, index1, index2);
}

int LuaStateView::rawget(int index) {
  return lua_rawget(L, index);
}

int LuaStateView::rawgeti(int index, lua_Integer n) {
  return lua_rawgeti(L, index, n);
}

int LuaStateView::rawgetp(int index, const void* p) {
  return lua_rawgetp(L, index, p);
}

size_t LuaStateView::rawlen(int index) {
  return lua_rawlen(L, index);
}

void LuaStateView::rawset(int index) {
  return lua_rawset(L, index);
}

void LuaStateView::rawseti(int index, lua_Integer i) {
  return lua_rawseti(L, index, i);
}

void LuaStateView::rawsetp(int index, const void* p) {
  return lua_rawsetp(L, index, p);
}

void LuaStateView::register_(const char* name, lua_CFunction f) {
  return lua_register(L, name, f);
}

void LuaStateView::remove(int index) {
  return lua_remove(L, index);
}

void LuaStateView::replace(int index) {
  return lua_replace(L, index);
}

int LuaStateView::resume(lua_State* from, int nargs) {
  return lua_resume(L, from, nargs);
}

void LuaStateView::rotate(int idx, int n) {
  return lua_rotate(L, idx, n);
}

void LuaStateView::setallocf(lua_Alloc f, void* ud) {
  return lua_setallocf(L, f, ud);
}

void LuaStateView::setfield(int index, const char* k) {
  return lua_setfield(L, index, k);
}

void LuaStateView::setglobal(const char* name) {
  return lua_setglobal(L, name);
}

void LuaStateView::seti(int index, lua_Integer n) {
  return lua_seti(L, index, n);
}

int LuaStateView::setmetatable(int index) {
  return lua_setmetatable(L, index);
}

void LuaStateView::settable(int index) {
  return lua_settable(L, index);
}

void LuaStateView::settop(int index) {
  return lua_settop(L, index);
}

void LuaStateView::setuservalue(int index) {
  return lua_setuservalue(L, index);
}

int LuaStateView::status() {
  return lua_status(L);
}

size_t LuaStateView::stringtonumber(const char* s) {
  return lua_stringtonumber(L, s);
}

int LuaStateView::toboolean(int index) {
  return lua_toboolean(L, index);
}

lua_CFunction LuaStateView::tocfunction(int index) {
  return lua_tocfunction(L, index);
}

lua_Integer LuaStateView::tointeger(int index) {
  return lua_tointeger(L, index);
}

lua_Integer LuaStateView::tointegerx(int index, int* isnum) {
  return lua_tointegerx(L, index, isnum);
}

const char* LuaStateView::tolstring(int index, size_t* len) {
  return lua_tolstring(L, index, len);
}

lua_Number LuaStateView::tonumber(int index) {
  return lua_tonumber(L, index);
}

lua_Number LuaStateView::tonumberx(int index, int* isnum) {
  return lua_tonumberx(L, index, isnum);
}

const void* LuaStateView::topointer(int index) {
  return lua_topointer(L, index);
}

const char* LuaStateView::tostring(int index) {
  return lua_tostring(L, index);
}

void* LuaStateView::touserdata(int index) {
  return lua_touserdata(L, index);
}

int LuaStateView::type(int index) {
  return lua_type(L, index);
}

const char* LuaStateView::typename_(int tp) {
  return lua_typename(L, tp);
}

const lua_Number* LuaStateView::version() {
  return lua_version(L);
}

void LuaStateView::xmove(lua_State* from, lua_State* to, int n) {
  return lua_xmove(from, to, n);
}

int LuaStateView::yield(int nresults) {
  return lua_yield(L, nresults);
}

int LuaStateView::yieldk(int nresults, lua_KContext ctx, lua_KFunction k) {
  return lua_yieldk(L, nresults, ctx, k);
}

void LuaStateView::sethook(lua_Hook f, int mask, int count) {
  return lua_sethook(L, f, mask, count);
}

const char* LuaStateView::setlocal(const lua_Debug* ar, int n) {
  return lua_setlocal(L, ar, n);
}

const char* LuaStateView::setupvalue(int funcindex, int n) {
  return lua_setupvalue(L, funcindex, n);
}

void* LuaStateView::upvalueid(int funcindex, int n) {
  return lua_upvalueid(L, funcindex, n);
}

void LuaStateView::upvaluejoin(int funcindex1, int n1, int funcindex2, int n2) {
  return lua_upvaluejoin(L, funcindex1, n1, funcindex2, n2);
}

void LuaStateView::argcheck(int cond, int arg, const char* extramsg) {
  return luaL_argcheck(L, cond, arg, extramsg);
}

int LuaStateView::argerror(int arg, const char* extramsg) {
  return luaL_argerror(L, arg, extramsg);
}

void LuaStateView::buffinit(luaL_Buffer* B) {
  return luaL_buffinit(L, B);
}

char* LuaStateView::buffinitsize(luaL_Buffer* B, size_t sz) {
  return luaL_buffinitsize(L, B, sz);
}

int LuaStateView::callmeta(int obj, const char* e) {
  return luaL_callmeta(L, obj, e);
}

void LuaStateView::checkany(int arg) {
  return luaL_checkany(L, arg);
}

lua_Integer LuaStateView::checkinteger(int arg) {
  return luaL_checkinteger(L, arg);
}

const char* LuaStateView::checklstring(int arg, size_t* l) {
  return luaL_checklstring(L, arg, l);
}

lua_Number LuaStateView::checknumber(int arg) {
  return luaL_checknumber(L, arg);
}

int LuaStateView::checkoption(int arg, const char* def,
                              const char* const lst[]) {
  return luaL_checkoption(L, arg, def, lst);
}

void LuaStateView::checkstack(int sz, const char* msg) {
  return luaL_checkstack(L, sz, msg);
}

const char* LuaStateView::checkstring(int arg) {
  return luaL_checkstring(L, arg);
}

void LuaStateView::checktype(int arg, int t) {
  return luaL_checktype(L, arg, t);
}

void* LuaStateView::checkudata(int arg, const char* tname) {
  return luaL_checkudata(L, arg, tname);
}

void LuaStateView::checkversion() {
  return luaL_checkversion(L);
}

int LuaStateView::dofile(const char* filename) {
  return luaL_dofile(L, filename);
}

int LuaStateView::dostring(const char* str) {
  return luaL_dostring(L, str);
}

int LuaStateView::error(const char* fmt, ...) {
  va_list argp;
  va_start(argp, fmt);
  luaL_where(L, 1);
  lua_pushvfstring(L, fmt, argp);
  va_end(argp);
  lua_concat(L, 2);
  return lua_error(L);
}

int LuaStateView::execresult(int stat) {
  return luaL_execresult(L, stat);
}

int LuaStateView::fileresult(int stat, const char* fname) {
  return luaL_fileresult(L, stat, fname);
}

int LuaStateView::getmetafield(int obj, const char* e) {
  return luaL_getmetafield(L, obj, e);
}

int LuaStateView::getmetatable(const char* tname) {
  return luaL_getmetatable(L, tname);
}

int LuaStateView::getsubtable(int idx, const char* fname) {
  return luaL_getsubtable(L, idx, fname);
}

const char* LuaStateView::gsub(const char* s, const char* p, const char* r) {
  return luaL_gsub(L, s, p, r);
}

lua_Integer LuaStateView::lenL(int index) {
  return luaL_len(L, index);
}

int LuaStateView::loadbuffer(const char* buff, size_t sz, const char* name) {
  return luaL_loadbuffer(L, buff, sz, name);
}

int LuaStateView::loadbufferx(const char* buff, size_t sz, const char* name,
                              const char* mode) {
  return luaL_loadbufferx(L, buff, sz, name, mode);
}

int LuaStateView::loadfile(const char* filename) {
  return luaL_loadfile(L, filename);
}

int LuaStateView::loadfilex(const char* filename, const char* mode) {
  return luaL_loadfilex(L, filename, mode);
}

int LuaStateView::loadstring(const char* s) {
  return luaL_loadstring(L, s);
}

void LuaStateView::newlib(const luaL_Reg l[]) {
  luaL_newlib(L, l);
}

void LuaStateView::newlibtable(const luaL_Reg l[]) {
  luaL_newlibtable(L, l);
}

int LuaStateView::newmetatable(const char* tname) {
  return luaL_newmetatable(L, tname);
}

void LuaStateView::openlibs() {
  return luaL_openlibs(L);
}

lua_Integer LuaStateView::optinteger(int arg, lua_Integer d) {
  return luaL_optinteger(L, arg, d);
}

const char* LuaStateView::optlstring(int arg, const char* d, size_t* l) {
  return luaL_optlstring(L, arg, d, l);
}

lua_Number LuaStateView::optnumber(int arg, lua_Number d) {
  return luaL_optnumber(L, arg, d);
}

const char* LuaStateView::optstring(int arg, const char* d) {
  return luaL_optstring(L, arg, d);
}

int LuaStateView::ref(int t) {
  return luaL_ref(L, t);
}

void LuaStateView::requiref(const char* modname, lua_CFunction openf, int glb) {
  return luaL_requiref(L, modname, openf, glb);
}

void LuaStateView::setfuncs(const luaL_Reg* l, int nup) {
  return luaL_setfuncs(L, l, nup);
}

void LuaStateView::setmetatable(const char* tname) {
  return luaL_setmetatable(L, tname);
}

void* LuaStateView::testudata(int arg, const char* tname) {
  return luaL_testudata(L, arg, tname);
}

const char* LuaStateView::tolstringL(int idx, size_t* len) {
  return luaL_tolstring(L, idx, len);
}

const char* LuaStateView::typenameL(int index) {
  return luaL_typename(L, index);
}

void LuaStateView::unref(int t, int ref) {
  return luaL_unref(L, t, ref);
}

void LuaStateView::where(int lvl) {
  return luaL_where(L, lvl);
}
