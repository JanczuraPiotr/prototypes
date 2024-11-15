@echo off
cmake CMakeLists.txt ^
	-DCMAKE_BUILD_TYPE=Release ^
	-B/c/tmp/cmake/cmd/dynamic_library/prototype/cmake-release 
	

@echo on