@echo off

cmake --build /c/tmp/cmake/cmd/dynamic_library/prototype/cmake-release

cd app-java

mvn package

cd ..

@echo on