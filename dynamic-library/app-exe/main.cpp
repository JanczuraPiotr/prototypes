#include <iostream>

#include "lib.h"

int main()
{
    start();

    print("String without decoration.");

    const char *napis = decorate("String with decpration.");
    if (napis) {
        print(napis);
        delete[] napis;
    }

    return 0;
}