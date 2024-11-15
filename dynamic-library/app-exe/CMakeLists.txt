project(app)

set(PROJECT_DIR                     ${PROJECT_SOURCE_DIR}/..)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${PROJECT_DIR}/bin)
set(LIB_BIN_DIR                     ${PROJECT_DIR}/bin)
set(LIB_SOURCE_DIR                  ${PROJECT_DIR}/lib)

include_directories (${LIB_SOURCE_DIR})

add_executable (${PROJECT_NAME} main.cpp ${LIB_SOURCE_DIR}/lib.h)

target_link_libraries (${PROJECT_NAME} lib )