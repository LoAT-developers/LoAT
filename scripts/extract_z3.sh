#!/bin/bash
docker build --target z3-binary -t z3-binary .
docker create -ti --name z3_dummy z3-binary bash
docker cp z3_dummy:/usr/bin/z3 ./build/release/z3
docker rm -f z3_dummy
