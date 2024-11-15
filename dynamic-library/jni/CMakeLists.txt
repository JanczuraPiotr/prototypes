project(jni)

set(PROJECT_DIR                     ${PROJECT_SOURCE_DIR}/..)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${PROJECT_DIR}/bin)
set(LIB_BIN_DIR                     ${PROJECT_DIR}/bin)
set(LIB_SOURCE_DIR                  ${PROJECT_DIR}/lib)

set(JAVA_HOME $ENV{JAVA_HOME})
message(STATUS "JAVA_HOME == ${JAVA_HOME}")

if (SYS_TARGET_WIN)
    message(${CMAKE_CURRENT_LIST_FILE}:${CMAKE_CURRENT_LIST_LINE})

    set(JAVA_AWT_LIBRARY "${JAVA_HOME}/lib/libjawt.so")
    set(JAVA_JVM_LIBRARY "${JAVA_HOME}/lib/server/libjvm.so")

    include_directories("c:/Program Files/Microsoft/jdk-21.0.5.11-hotspot/include")
    include_directories("c:/Program Files/Microsoft/jdk-21.0.5.11-hotspot/include/win32")
elseif (SYS_TARHET_LIN)
    message(${CMAKE_CURRENT_LIST_FILE}:${CMAKE_CURRENT_LIST_LINE})
else ()
    message(${CMAKE_CURRENT_LIST_FILE}:${CMAKE_CURRENT_LIST_LINE})
endif ()

find_package(JNI REQUIRED)

if (JNI_FOUND)
    message(STATUS "JNI found!")
    message(STATUS "JNI_INCLUDE_DIRS: ${JNI_INCLUDE_DIRS}")
    message(STATUS "JNI_LIBRARIES: ${JNI_LIBRARIES}")
else()
    message(FATAL_ERROR "Unable to find JNI")
endif()

if (SYS_TARGET_WIN)
    set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -luser32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")

    target_link_libraries(${PROJECT_NAME}
            winpthread
            usb-1.0
            boost_date_time
            boost_filesystem
    )

    set_target_properties(${PROJECT_NAME} PROPERTIES
            PREFIX ""
            SUFFIX ${SUFFIX}
            LINK_FLAGS "-shared -Wl,--add-stdcall-alias "
            COMPILE_OPTIONS  "-m64"  LINK_OPTIONS "-m64"
    )

endif ()

include_directories(${SRC_ROOT_DIR}/lib)
include_directories(${JNI_INCLUDE_DIRS})
add_library(jni SHARED pl_janczura_Jni.cpp)

#set_target_properties(lib_jni PROPERTIES
#        PREFIX "" # Bez tego biblioteka nazywał by się liblib_jni.*
#)

#set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ ${CMAKE_CXX_STANDARD_LIBRARIES}")