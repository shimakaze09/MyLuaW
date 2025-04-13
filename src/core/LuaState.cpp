#include <MyLuaW/LuaState.h>

using namespace My;

LuaState::LuaState(std::shared_ptr<lua_State> L,
                   std::shared_ptr<lua_State> main)
    : L{std::move(L)}, main{std::move(main)} {}

LuaState::LuaState(std::shared_ptr<lua_State> L) : LuaState(L, L) {}

LuaState::LuaState() : L{luaL_newstate(), lua_close}, main{L} {}

LuaState::LuaState(lua_Alloc f, void* userdata)
    : L{lua_newstate(f, userdata), lua_close}, main{L} {}

int LuaState::absindex(int idx) {
  return lua_absindex(L.get(), idx);
}

void LuaState::arith(int op) {
  return lua_arith(L.get(), op);
}

lua_CFunction LuaState::atpanic(lua_CFunction panicf) {
  return lua_atpanic(L.get(), panicf);
}

void LuaState::call(int nargs, int nresults) {
  return lua_call(L.get(), nargs, nresults);
}

void LuaState::callk(int nargs, int nresults, lua_KContext ctx,
                     lua_KFunction k) {
  return lua_callk(L.get(), nargs, nresults, ctx, k);
}

int LuaState::checkstack(int n) {
  return lua_checkstack(L.get(), n);
}

int LuaState::compare(int index1, int index2, int op) {
  return lua_compare(L.get(), index1, index2, op);
}

void LuaState::concat(int n) {
  return lua_concat(L.get(), n);
}

void LuaState::copy(int fromidx, int toidx) {
  return lua_copy(L.get(), fromidx, toidx);
}

void LuaState::createtable(int narr, int nrec) {
  return lua_createtable(L.get(), narr, nrec);
}

int LuaState::dump(lua_Writer writer, void* data, int strip) {
  return lua_dump(L.get(), writer, data, strip);
}

int LuaState::error() {
  return lua_error(L.get());
}

int LuaState::gc(int what, int data) {
  return lua_gc(L.get(), what, data);
}

lua_Alloc LuaState::getallocf(void** ud) {
  return lua_getallocf(L.get(), ud);
}

int LuaState::getfield(int index, const char* k) {
  return lua_getfield(L.get(), index, k);
}

void* LuaState::getextraspace() {
  return lua_getextraspace(L.get());
}

int LuaState::getglobal(const char* name) {
  return lua_getglobal(L.get(), name);
}

lua_Hook LuaState::gethook() {
  return lua_gethook(L.get());
}

int LuaState::gethookcount() {
  return lua_gethookcount(L.get());
}

int LuaState::gethookmask() {
  return lua_gethookmask(L.get());
}

int LuaState::geti(int index, lua_Integer i) {
  return lua_geti(L.get(), index, i);
}

int LuaState::getinfo(const char* what, lua_Debug* ar) {
  return lua_getinfo(L.get(), what, ar);
}

const char* LuaState::getlocal(const lua_Debug* ar, int n) {
  return lua_getlocal(L.get(), ar, n);
}

int LuaState::getmetatable(int index) {
  return lua_getmetatable(L.get(), index);
}

int LuaState::getstack(int level, lua_Debug* ar) {
  return lua_getstack(L.get(), level, ar);
}

int LuaState::gettable(int index) {
  return lua_gettable(L.get(), index);
}

int LuaState::gettop() {
  return lua_gettop(L.get());
}

const char* LuaState::getupvalue(int funcindex, int n) {
  return lua_getupvalue(L.get(), funcindex, n);
}

int LuaState::getuservalue(int index) {
  return lua_getuservalue(L.get(), index);
}

void LuaState::insert(int index) {
  return lua_insert(L.get(), index);
}

int LuaState::isboolean(int index) {
  return lua_isboolean(L.get(), index);
}

int LuaState::iscfunction(int index) {
  return lua_iscfunction(L.get(), index);
}

int LuaState::isfunction(int index) {
  return lua_isfunction(L.get(), index);
}

int LuaState::isinteger(int index) {
  return lua_isinteger(L.get(), index);
}

int LuaState::islightuserdata(int index) {
  return lua_islightuserdata(L.get(), index);
}

int LuaState::isnil(int index) {
  return lua_isnil(L.get(), index);
}

int LuaState::isnone(int index) {
  return lua_isnone(L.get(), index);
}

int LuaState::isnoneornil(int index) {
  return lua_isnoneornil(L.get(), index);
}

int LuaState::isnumber(int index) {
  return lua_isnumber(L.get(), index);
}

int LuaState::isstring(int index) {
  return lua_isstring(L.get(), index);
}

int LuaState::istable(int index) {
  return lua_istable(L.get(), index);
}

int LuaState::isthread(int index) {
  return lua_isthread(L.get(), index);
}

int LuaState::isuserdata(int index) {
  return lua_isuserdata(L.get(), index);
}

int LuaState::isyieldable() {
  return lua_isyieldable(L.get());
}

void LuaState::len(int index) {
  return lua_len(L.get(), index);
}

int LuaState::load(lua_Reader reader, void* data, const char* chunkname,
                   const char* mode) {
  return lua_load(L.get(), reader, data, chunkname, mode);
}

void LuaState::newtable() {
  return lua_newtable(L.get());
}

LuaState LuaState::newthread() {
  return {L, std::shared_ptr<lua_State>{lua_newthread(L.get()), [](lua_State*) {
                                        }}};
}

void* LuaState::newuserdata(size_t size) {
  return lua_newuserdata(L.get(), size);
}

int LuaState::next(int index) {
  return lua_next(L.get(), index);
}

int LuaState::pcall(int nargs, int nresults, int msgh) {
  return lua_pcall(L.get(), nargs, nresults, msgh);
}

int LuaState::pcallk(int nargs, int nresults, int msgh, lua_KContext ctx,
                     lua_KFunction k) {
  return lua_pcallk(L.get(), nargs, nresults, msgh, ctx, k);
}

void LuaState::pop(int n) {
  return lua_pop(L.get(), n);
}

void LuaState::pushboolean(int b) {
  return lua_pushboolean(L.get(), b);
}

void LuaState::pushcclosure(lua_CFunction fn, int n) {
  return lua_pushcclosure(L.get(), fn, n);
}

void LuaState::pushcfunction(lua_CFunction f) {
  return lua_pushcfunction(L.get(), f);
}

const char* LuaState::pushfstring(const char* fmt, ...) {
  va_list argp;
  va_start(argp, fmt);
  const char* rst = pushvfstring(fmt, argp);
  va_end(argp);
  return rst;
}

int LuaState::pushglobaltable() {
  return lua_pushglobaltable(L.get());
}

void LuaState::pushinteger(lua_Integer n) {
  return lua_pushinteger(L.get(), n);
}

void LuaState::pushlightuserdata(void* p) {
  return lua_pushlightuserdata(L.get(), p);
}

const char* LuaState::pushlstring(const char* s, size_t len) {
  return lua_pushlstring(L.get(), s, len);
}

void LuaState::pushnil() {
  return lua_pushnil(L.get());
}

void LuaState::pushnumber(lua_Number n) {
  return lua_pushnumber(L.get(), n);
}

const char* LuaState::pushstring(const char* s) {
  return lua_pushstring(L.get(), s);
}

int LuaState::pushthread() {
  return lua_pushthread(L.get());
}

void LuaState::pushvalue(int index) {
  return lua_pushvalue(L.get(), index);
}

const char* LuaState::pushvfstring(const char* fmt, va_list argp) {
  return lua_pushvfstring(L.get(), fmt, argp);
}

int LuaState::rawequal(int index1, int index2) {
  return lua_rawequal(L.get(), index1, index2);
}

int LuaState::rawget(int index) {
  return lua_rawget(L.get(), index);
}

int LuaState::rawgeti(int index, lua_Integer n) {
  return lua_rawgeti(L.get(), index, n);
}

int LuaState::rawgetp(int index, const void* p) {
  return lua_rawgetp(L.get(), index, p);
}

size_t LuaState::rawlen(int index) {
  return lua_rawlen(L.get(), index);
}

void LuaState::rawset(int index) {
  return lua_rawset(L.get(), index);
}

void LuaState::rawseti(int index, lua_Integer i) {
  return lua_rawseti(L.get(), index, i);
}

void LuaState::rawsetp(int index, const void* p) {
  return lua_rawsetp(L.get(), index, p);
}

void LuaState::register_(const char* name, lua_CFunction f) {
  return lua_register(L.get(), name, f);
}

void LuaState::remove(int index) {
  return lua_remove(L.get(), index);
}

void LuaState::replace(int index) {
  return lua_replace(L.get(), index);
}

int LuaState::resume(lua_State* from, int nargs) {
  return lua_resume(L.get(), from, nargs);
}

void LuaState::rotate(int idx, int n) {
  return lua_rotate(L.get(), idx, n);
}

void LuaState::setallocf(lua_Alloc f, void* ud) {
  return lua_setallocf(L.get(), f, ud);
}

void LuaState::setfield(int index, const char* k) {
  return lua_setfield(L.get(), index, k);
}

void LuaState::setglobal(const char* name) {
  return lua_setglobal(L.get(), name);
}

void LuaState::seti(int index, lua_Integer n) {
  return lua_seti(L.get(), index, n);
}

int LuaState::setmetatable(int index) {
  return lua_setmetatable(L.get(), index);
}

void LuaState::settable(int index) {
  return lua_settable(L.get(), index);
}

void LuaState::settop(int index) {
  return lua_settop(L.get(), index);
}

void LuaState::setuservalue(int index) {
  return lua_setuservalue(L.get(), index);
}

int LuaState::status() {
  return lua_status(L.get());
}

size_t LuaState::stringtonumber(const char* s) {
  return lua_stringtonumber(L.get(), s);
}

int LuaState::toboolean(int index) {
  return lua_toboolean(L.get(), index);
}

lua_CFunction LuaState::tocfunction(int index) {
  return lua_tocfunction(L.get(), index);
}

lua_Integer LuaState::tointeger(int index) {
  return lua_tointeger(L.get(), index);
}

lua_Integer LuaState::tointegerx(int index, int* isnum) {
  return lua_tointegerx(L.get(), index, isnum);
}

const char* LuaState::tolstring(int index, size_t* len) {
  return lua_tolstring(L.get(), index, len);
}

lua_Number LuaState::tonumber(int index) {
  return lua_tonumber(L.get(), index);
}

lua_Number LuaState::tonumberx(int index, int* isnum) {
  return lua_tonumberx(L.get(), index, isnum);
}

const void* LuaState::topointer(int index) {
  return lua_topointer(L.get(), index);
}

const char* LuaState::tostring(int index) {
  return lua_tostring(L.get(), index);
}

void* LuaState::touserdata(int index) {
  return lua_touserdata(L.get(), index);
}

int LuaState::type(int index) {
  return lua_type(L.get(), index);
}

const char* LuaState::typename_(int tp) {
  return lua_typename(L.get(), tp);
}

const lua_Number* LuaState::version() {
  return lua_version(L.get());
}

void LuaState::xmove(lua_State* from, lua_State* to, int n) {
  return lua_xmove(from, to, n);
}

int LuaState::yield(int nresults) {
  return lua_yield(L.get(), nresults);
}

int LuaState::yieldk(int nresults, lua_KContext ctx, lua_KFunction k) {
  return lua_yieldk(L.get(), nresults, ctx, k);
}

void LuaState::sethook(lua_Hook f, int mask, int count) {
  return lua_sethook(L.get(), f, mask, count);
}

const char* LuaState::setlocal(const lua_Debug* ar, int n) {
  return lua_setlocal(L.get(), ar, n);
}

const char* LuaState::setupvalue(int funcindex, int n) {
  return lua_setupvalue(L.get(), funcindex, n);
}

void* LuaState::upvalueid(int funcindex, int n) {
  return lua_upvalueid(L.get(), funcindex, n);
}

void LuaState::upvaluejoin(int funcindex1, int n1, int funcindex2, int n2) {
  return lua_upvaluejoin(L.get(), funcindex1, n1, funcindex2, n2);
}

void LuaState::argcheck(int cond, int arg, const char* extramsg) {
  return luaL_argcheck(L.get(), cond, arg, extramsg);
}

int LuaState::argerror(int arg, const char* extramsg) {
  return luaL_argerror(L.get(), arg, extramsg);
}

void LuaState::buffinit(luaL_Buffer* B) {
  return luaL_buffinit(L.get(), B);
}

char* LuaState::buffinitsize(luaL_Buffer* B, size_t sz) {
  return luaL_buffinitsize(L.get(), B, sz);
}

int LuaState::callmeta(int obj, const char* e) {
  return luaL_callmeta(L.get(), obj, e);
}

void LuaState::checkany(int arg) {
  return luaL_checkany(L.get(), arg);
}

lua_Integer LuaState::checkinteger(int arg) {
  return luaL_checkinteger(L.get(), arg);
}

const char* LuaState::checklstring(int arg, size_t* l) {
  return luaL_checklstring(L.get(), arg, l);
}

lua_Number LuaState::checknumber(int arg) {
  return luaL_checknumber(L.get(), arg);
}

int LuaState::checkoption(int arg, const char* def, const char* const lst[]) {
  return luaL_checkoption(L.get(), arg, def, lst);
}

void LuaState::checkstack(int sz, const char* msg) {
  return luaL_checkstack(L.get(), sz, msg);
}

const char* LuaState::checkstring(int arg) {
  return luaL_checkstring(L.get(), arg);
}

void LuaState::checktype(int arg, int t) {
  return luaL_checktype(L.get(), arg, t);
}

void* LuaState::checkudata(int arg, const char* tname) {
  return luaL_checkudata(L.get(), arg, tname);
}

void LuaState::checkversion() {
  return luaL_checkversion(L.get());
}

int LuaState::dofile(const char* filename) {
  return luaL_dofile(L.get(), filename);
}

int LuaState::dostring(const char* str) {
  return luaL_dostring(L.get(), str);
}

int LuaState::error(const char* fmt, ...) {
  va_list argp;
  va_start(argp, fmt);
  luaL_where(L.get(), 1);
  lua_pushvfstring(L.get(), fmt, argp);
  va_end(argp);
  lua_concat(L.get(), 2);
  return lua_error(L.get());
}

int LuaState::execresult(int stat) {
  return luaL_execresult(L.get(), stat);
}

int LuaState::fileresult(int stat, const char* fname) {
  return luaL_fileresult(L.get(), stat, fname);
}

int LuaState::getmetafield(int obj, const char* e) {
  return luaL_getmetafield(L.get(), obj, e);
}

int LuaState::getmetatable(const char* tname) {
  return luaL_getmetatable(L.get(), tname);
}

int LuaState::getsubtable(int idx, const char* fname) {
  return luaL_getsubtable(L.get(), idx, fname);
}

const char* LuaState::gsub(const char* s, const char* p, const char* r) {
  return luaL_gsub(L.get(), s, p, r);
}

lua_Integer LuaState::lenL(int index) {
  return luaL_len(L.get(), index);
}

int LuaState::loadbuffer(const char* buff, size_t sz, const char* name) {
  return luaL_loadbuffer(L.get(), buff, sz, name);
}

int LuaState::loadbufferx(const char* buff, size_t sz, const char* name,
                          const char* mode) {
  return luaL_loadbufferx(L.get(), buff, sz, name, mode);
}

int LuaState::loadfile(const char* filename) {
  return luaL_loadfile(L.get(), filename);
}

int LuaState::loadfilex(const char* filename, const char* mode) {
  return luaL_loadfilex(L.get(), filename, mode);
}

int LuaState::loadstring(const char* s) {
  return luaL_loadstring(L.get(), s);
}

void LuaState::newlib(const luaL_Reg l[]) {
  luaL_newlib(L.get(), l);
}

void LuaState::newlibtable(const luaL_Reg l[]) {
  luaL_newlibtable(L.get(), l);
}

int LuaState::newmetatable(const char* tname) {
  return luaL_newmetatable(L.get(), tname);
}

void LuaState::openlibs() {
  return luaL_openlibs(L.get());
}

lua_Integer LuaState::optinteger(int arg, lua_Integer d) {
  return luaL_optinteger(L.get(), arg, d);
}

const char* LuaState::optlstring(int arg, const char* d, size_t* l) {
  return luaL_optlstring(L.get(), arg, d, l);
}

lua_Number LuaState::optnumber(int arg, lua_Number d) {
  return luaL_optnumber(L.get(), arg, d);
}

const char* LuaState::optstring(int arg, const char* d) {
  return luaL_optstring(L.get(), arg, d);
}

int LuaState::ref(int t) {
  return luaL_ref(L.get(), t);
}

void LuaState::requiref(const char* modname, lua_CFunction openf, int glb) {
  return luaL_requiref(L.get(), modname, openf, glb);
}

void LuaState::setfuncs(const luaL_Reg* l, int nup) {
  return luaL_setfuncs(L.get(), l, nup);
}

void LuaState::setmetatable(const char* tname) {
  return luaL_setmetatable(L.get(), tname);
}

void* LuaState::testudata(int arg, const char* tname) {
  return luaL_testudata(L.get(), arg, tname);
}

const char* LuaState::tolstringL(int idx, size_t* len) {
  return luaL_tolstring(L.get(), idx, len);
}

const char* LuaState::typenameL(int index) {
  return luaL_typename(L.get(), index);
}

void LuaState::unref(int t, int ref) {
  return luaL_unref(L.get(), t, ref);
}

void LuaState::where(int lvl) {
  return luaL_where(L.get(), lvl);
}
