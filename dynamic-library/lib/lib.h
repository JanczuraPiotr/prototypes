#ifndef DYNAMIC_LIBRARY_LIB_H
#define DYNAMIC_LIBRARY_LIB_H

#include <string>

#if defined(SYS_TARGET_WIN)
    #if defined(BUILD_DLL)
        #define __DECLSPEC__ __declspec (dllexport)
        #define __STDCALL__ __stdcall
    #else
        #define __DECLSPEC__ __declspec (dllimport)
        #define __STDCALL__
    #endif
#elif defined(SYS_TARGET_LIN)
    #define __DECLSPEC__
    #define __STDCALL__
#endif


#ifdef __cplusplus
extern "C" {
#endif

__DECLSPEC__ void __STDCALL__ print(const std::string &input);

#ifdef __cplusplus
}
#endif



#endif //DYNAMIC_LIBRARY_LIB_H