cmake_minimum_required(VERSION 3.20)
project(dynamic_library)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++")
set(SRC_ROOT_DIR ${PROJECT_SOURCE_DIR})

message("SRC_ROOT_DIR ${SRC_ROOT_DIR}")

if(DEFINED ENV{MSYSTEM} OR WIN32)
    set(SYS_TARGET_WIN 1)                   # na potrzeby cmake
    add_compile_definitions(SYS_TARGET_WIN) # na potrzeby kompilatora
    message("Rozpoznano Windows")
elseif (UNIX AND NOT APPLE)
    set(SYS_TARGET_LIN 1)                   # na potrzeby cmake
    add_compile_definitions(SYS_TARGET_LIN) # na potrzeby kompilatora
    message("Rozpoznano system rodziny Unix.")
else ()
    message(WARNING "Nie rozpoznano systemu operacyjnego!")
endif()

add_subdirectory(lib)
add_subdirectory(jni)
add_subdirectory(app-exe)
