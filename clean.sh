#!/bin/bash
echo "Clean current directory"
rm -rf CMakeCache.txt CMakeFiles cmake_install.cmake Makefile manage
echo "Clean chameleon directory"
cd chameleon && ./clean.sh
echo "Clean hiberlite directory"
cd hiberlite && ./clean.sh
