#!/bin/bash

# Reconfigures the cmake build directory and triggers a build. To be executed
# from a docker container where the LoAT root directory is mounted at
# /LoAT/. Reconfiguration is necessary to get the information whether the
# working tree is clean or not.

cd /LoAT/build/release
cmake -DCMAKE_BUILD_TYPE=Release ../../
make -j
