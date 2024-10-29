# dynamic-library


Przy pomocy :
https://stackoverflow.com/questions/23323741/building-of-executable-and-shared-library-with-cmake-runtimelinker-does-not-fin


Inicjalizacja:<br>
cmake CMakeLists.txt -Bcmake-release

Kompilacja całości:<br>
cmake --build cmake-release

Katalogi app, bin, lib obsługują aplikację i bibliotekę dll tworzone jednocześnie, ale jako osobne pliki w taki sposób,
że plik lib.dll i lib.h można przekazać do tworzenia innego projektu.
