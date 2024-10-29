cmake_minimum_required(VERSION 3.20)
project(dynamic_library)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++")

if(UNIX AND NOT APPLE)
    set(SYS_TARGET_LIN 1)                   # na potrzeby cmake
    add_compile_definitions(SYS_TARGET_LIN) # na potrzeby kompilatora
else()
    set(SYS_TARGET_WIN 1)                   # na potrzeby cmake
    add_compile_definitions(SYS_TARGET_WIN) # na potrzeby kompilatora
endif()

add_subdirectory(lib)
add_subdirectory(app)
