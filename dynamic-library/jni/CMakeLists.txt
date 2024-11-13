project(lib_jni)

set(PROJECT_DIR                     ${PROJECT_SOURCE_DIR}/..)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${PROJECT_DIR}/bin)
set(LIB_BIN_DIR                     ${PROJECT_DIR}/bin)
set(LIB_SOURCE_DIR                  ${PROJECT_DIR}/lib)

set(JAVA_HOME $ENV{JAVA_HOME})
message(STATUS "JAVA_HOME == ${JAVA_HOME}")

if (SYS_TARGET_WIN)
    set(JAVA_AWT_LIBRARY "${JAVA_HOME}/lib/libjawt.so")
    set(JAVA_JVM_LIBRARY "${JAVA_HOME}/lib/server/libjvm.so")
    include_directories("c:/Program Files/Microsoft/jdk-21.0.5.11-hotspot/include")
    include_directories("c:/Program Files/Microsoft/jdk-21.0.5.11-hotspot/include/win32")
else ()
endif ()

find_package(JNI REQUIRED)

if (JNI_FOUND)
    message(STATUS "JNI found!")
    message(STATUS "JNI_INCLUDE_DIRS: ${JNI_INCLUDE_DIRS}")
    message(STATUS "JNI_LIBRARIES: ${JNI_LIBRARIES}")
else()
    message(FATAL_ERROR "Unable to find JNI")
endif()

include_directories(${JNI_INCLUDE_DIRS})
add_library(lib_jni SHARED pl_janczura_LibJni.cpp)

set_target_properties(lib_jni PROPERTIES
        PREFIX "" # Bez tego biblioteka nazywał by się liblib_jni.*
)

