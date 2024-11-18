project(jni)
include(../function.cmake)

set(PROJECT_DIR                     ${PROJECT_SOURCE_DIR}/..)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${PROJECT_DIR}/bin)
set(LIB_BIN_DIR                     ${PROJECT_DIR}/bin)
set(LIB_SOURCE_DIR                  ${PROJECT_DIR}/lib)

convert_to_posix_path("$ENV{JAVA_HOME}" JAVA_HOME)
convert_to_posix_path("$ENV{JDK_HOME}" JDK_HOME)

if (SYS_TARGET_WIN)
    message(${CMAKE_CURRENT_LIST_FILE}:${CMAKE_CURRENT_LIST_LINE})

    add_compile_definitions(BUILD_DLL)

    message(STATUS "JAVA_HOME pokonwersji : ${JAVA_HOME}")
    message(STATUS "JDK_HOME po konwersji : ${JDK_HOME}")

    set(JAVA_AWT_LIBRARY "${JAVA_HOME}/lib/libjawt.so")
    set(JAVA_JVM_LIBRARY "${JAVA_HOME}/lib/server/libjvm.so")

    include_directories(${JNI_INCLUDE_DIRS})

elseif (SYS_TARGET_LIN)
    message(${CMAKE_CURRENT_LIST_FILE}:${CMAKE_CURRENT_LIST_LINE})
else ()
    message(${CMAKE_CURRENT_LIST_FILE}:${CMAKE_CURRENT_LIST_LINE})
endif ()

find_package(Java REQUIRED)
find_package(JNI REQUIRED)

if (JNI_FOUND)
    message(STATUS "JNI found!")
    message(STATUS "JNI_INCLUDE_DIRS: ${JNI_INCLUDE_DIRS}")
    message(STATUS "JNI_LIBRARIES: ${JNI_LIBRARIES}")
else()
    message(FATAL_ERROR "Unable to find JNI")
endif()

message(${CMAKE_CURRENT_LIST_FILE}:${CMAKE_CURRENT_LIST_LINE}"  "${PROJECT_NAME})
message(${CMAKE_CURRENT_LIST_FILE}:${CMAKE_CURRENT_LIST_LINE}"  "${JNI_INCLUDE_DIRS})
message(${CMAKE_CURRENT_LIST_FILE}:${CMAKE_CURRENT_LIST_LINE}"  "${JNI_LIBRARIES})

include_directories(${SRC_ROOT_DIR}/lib)
include_directories(${JNI_INCLUDE_DIRS})


add_library(${PROJECT_NAME} SHARED pl_janczura_Jni.cpp ../lib/lib.cpp)

if (SYS_TARGET_WIN)
    set_target_properties(${PROJECT_NAME} PROPERTIES
            PREFIX "" # Bez tego biblioteka nazywał by się lib-jni.*
    )


elseif (SYS_TARGET_LIN)

#    set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ ${CMAKE_CXX_STANDARD_LIBRARIES}")

endif ()

#set_target_properties(lib_jni PROPERTIES
#        PREFIX "" # Bez tego biblioteka nazywał by się liblib_jni.*
#)

#set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ ${CMAKE_CXX_STANDARD_LIBRARIES}")