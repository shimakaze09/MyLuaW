SET(c_options "")
IF (MSVC)
    LIST(APPEND c_options "/wd4309")
ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    #
ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    #
ENDIF ()

ADD_TARGET(
        MODE STATIC
        SOURCE
        "${PROJECT_SOURCE_DIR}/include/MyLuaW"
        INC
        "${PROJECT_SOURCE_DIR}/include"
        LIB
        My::MyLua_core
)