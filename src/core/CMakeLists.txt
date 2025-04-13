ADD_TARGET(
        MODE STATIC
        SOURCE
        "${PROJECT_SOURCE_DIR}/include/MyLuaW"
        INC
        "${PROJECT_SOURCE_DIR}/include"
        LIB
        My::MyLua_core
)