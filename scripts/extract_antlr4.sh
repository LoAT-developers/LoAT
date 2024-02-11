#!/bin/bash
echo "build..."
docker build --target antlr4 -t antlr4 -f ../docker/antlr4.Dockerfile .
echo "create..."
docker create -ti --name antlr4_dummy antlr4 sh
echo "cp..."
docker cp antlr4_dummy:/usr/local/lib/libantlr4-runtime.a ../lib
docker cp antlr4_dummy:/usr/local/include/antlr4-runtime ../include
echo "rm..."
docker rm -f antlr4_dummy
echo "done!"
