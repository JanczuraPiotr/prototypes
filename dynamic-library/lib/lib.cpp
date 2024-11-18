#include "lib.h"

#include<iostream>

#ifdef __cplusplus
extern "C" {
#endif


__DECLSPEC__ void __STDCALL__ start()
{
    static std::string timestamp = [] () {
        std::string date(__DATE__);
        std::string time(__TIME__);
        return "Library created at : " + date + " " + time;
    } ();

    print(timestamp.c_str());
}

__DECLSPEC__ void __STDCALL__ print(const char *input)
{
    if (input) {
        std::cout << input << std::endl;
    } else {
        std::cout << "" << std::endl;
    }
}

__DECLSPEC__ const char* __STDCALL__ decorate(const char *input)
{
    if (!input) {
        const char *ret = "{}";
        return ret;
    }

    std::string _input = "{ " + std::string(input) + " }";

    char *ret = new char[_input.length() + 1];
    _input.copy(ret, _input.length() + 1, 0);
    ret[_input.length()] = '\0';
    return ret;
}


#ifdef __cplusplus
}
#endif