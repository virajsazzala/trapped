#!/bin/sh

mkdir -p build

cmake -S . -B build
cmake --build build

./build/bin/trapped
