project(lib)

set(PROJECT_DIR                     ${PROJECT_SOURCE_DIR}/..)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${PROJECT_DIR}/bin)
set(LIB_BIN_DIR                     ${PROJECT_DIR}/bin)
set(LIB_SOURCE_DIR                  ${PROJECT_DIR}/lib)

if (SYS_TARGET_WIN)
    add_compile_definitions(BUILD_DLL)
else ()
endif ()

add_library(lib SHARED lib.cpp)

set_target_properties(lib PROPERTIES PREFIX "")

# Aby wygenerowana biblioteka była w komplecie z jej plikiem nagłówkowy,
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${LIB_SOURCE_DIR}/lib.h
        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/lib.h
)