#ifndef DYNAMIC_LIBRARY_LIB_H
#define DYNAMIC_LIBRARY_LIB_H


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



#ifdef __cplusplus
}
#endif



#endif //DYNAMIC_LIBRARY_LIB_H
