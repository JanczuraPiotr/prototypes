cmake_minimum_required(VERSION 3.20)
project(dynamic_library)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++")
set(SRC_ROOT_DIR ${PROJECT_SOURCE_DIR})

if(DEFINED ENV{MSYSTEM} OR WIN32)
    set(SYS_TARGET_WIN 1)                   # na potrzeby cmake
    add_compile_definitions(SYS_TARGET_WIN) # na potrzeby kompilatora
elseif (UNIX AND NOT APPLE)
    set(SYS_TARGET_LIN 1)                   # na potrzeby cmake
    add_compile_definitions(SYS_TARGET_LIN) # na potrzeby kompilatora
else ()
    message(FATAL_ERROR "Operating system not recognized!")
endif()

add_subdirectory(lib)
add_subdirectory(jni)
add_subdirectory(app-exe)
