#include <iostream>

#include "lib.h"

int main()
{
    print("String bez dekoracji.");

    const char *napis = decorate("String z dekoracją.");
    if (napis) {
        print(napis);
        delete[] napis;
    }

    return 0;
}