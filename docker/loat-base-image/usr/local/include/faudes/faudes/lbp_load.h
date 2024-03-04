/* Auto-generated file to define lua module loading for all enabled plugins */

/* 
The build system appends definitions of load functions for each plugin. 
They are resolved in libluafaudes. There is also a function luaopen_libfaudes() 
to include all supported plugins
*/

// have FAUDES_API 
#include "cfl_platform.h"

// have lua state defined
extern "C" {
#include "lua/lua.h"
}


// over all load
extern FAUDES_API int luaopen_faudes_allplugins(lua_State* L); 

// load known modules 
extern "C" {
 extern FAUDES_API int luaopen_faudes(lua_State* L); 
 extern FAUDES_API int luaopen_synthesis(lua_State* L); 
 extern FAUDES_API int luaopen_observer(lua_State* L); 
 extern FAUDES_API int luaopen_observability(lua_State* L); 
 extern FAUDES_API int luaopen_diagnosis(lua_State* L); 
 extern FAUDES_API int luaopen_hiosys(lua_State* L); 
 extern FAUDES_API int luaopen_iosystem(lua_State* L); 
 extern FAUDES_API int luaopen_multitasking(lua_State* L); 
 extern FAUDES_API int luaopen_coordinationcontrol(lua_State* L); 

}
