#!/bin/bash
rm -rf CMakeCache.txt CMakeFiles cmake_install.cmake Makefile manage
echo "clean chameleon"
cd chameleon && ./clean.sh
echo "clean hiberlite"
cd hiberlite && ./clean.sh
