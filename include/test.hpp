extern "C" {
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
}
void test_function(void) {
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	const char *lua_version = lua_pushfstring(L, "%s", LUA_VERSION);
	printf("Lua version: %s\n", lua_version);

	const char *lua_script = "print('Hello, world!')";
	int lua_result = luaL_dostring(L, lua_script);
	if (lua_result != LUA_OK) {
		const char *error_message = lua_tostring(L, -1);
		printf("Error: %s\n", error_message);
	}

	lua_close(L);
}