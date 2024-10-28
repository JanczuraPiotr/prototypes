cmake_minimum_required(VERSION 3.17)
project(dynamic_library)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++")

add_subdirectory(lib)
add_subdirectory(app)
