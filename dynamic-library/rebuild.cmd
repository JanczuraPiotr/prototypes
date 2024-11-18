@echo off

rm -R /c/tmp/cmake/cmd/dynamic_library/prototype/cmake-release

CALL prepare.cmd
CALL build.cmd

@echo on