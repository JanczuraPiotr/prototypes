#!/bin/bash

cmake --build ~/Projekty/tmp/cmake/cmd/dynamic_library/prototype/cmake-release

cd app-java

mvn package

cd ..
