#include "lib.h"

#include<iostream>
#include<string>

#ifdef __cplusplus
extern "C" {
#endif


__DECLSPEC__ void __STDCALL__ print(const std::string &input)
{
    std::cout << input << std::endl;
}

#ifdef __cplusplus
}
#endif