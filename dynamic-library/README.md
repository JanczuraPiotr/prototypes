# dynamic-library


Przy pomocy :
https://stackoverflow.com/questions/23323741/building-of-executable-and-shared-library-with-cmake-runtimelinker-does-not-fin


inicjacja :

cmake -G"Unix Makefiles" CMakeLists.txt


kompilacja całości :

make

kompilacja podprojektu :


make lib
<br>
make use-lib


Katalogi app, bin, lib obsługują aplikację i bibliotekę dll tworzone jednocześnie ale jako osobne pliki w taki sposób,
że plik lib.dll i lib.h można przekazać do tworzenia innego projektu.

Podprojekt - katalog subproject symuluje aplikację wykorzystującą lib.dll.
W katalogu subproject/app jest aplikacja. W katalogu subproject/bin są bibliotegi konieczne do pracy.
W katalogu subproject/lib są wymagane pliki źródłowe.