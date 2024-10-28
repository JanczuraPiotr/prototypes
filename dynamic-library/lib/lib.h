#ifndef DYNAMIC_LIBRARY_LIB_H
#define DYNAMIC_LIBRARY_LIB_H

#include <string>

#if BUILD_DLL
    #define __LEFT__ __declspec (dllexport)
    #define __RIGHT__ __stdcall
#else
    #define __LEFT__ __declspec (dllimport)
    #define __RIGHT__
#endif


#ifdef __cplusplus
extern "C" {
#endif

__LEFT__ void __RIGHT__ print(const std::string &input);

#ifdef __cplusplus
}
#endif



#endif //DYNAMIC_LIBRARY_LIB_H