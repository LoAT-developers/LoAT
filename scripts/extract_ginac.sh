#!/bin/bash
echo "build..."
docker build --target ginac -t ginac -f ../docker/ginac.Dockerfile .
echo "create..."
docker create -ti --name ginac_dummy ginac sh
echo "cp..."
docker cp ginac_dummy:/usr/local/lib64/libginac.a ../lib
docker cp ginac_dummy:/usr/local/include/ginac ../include
echo "rm..."
docker rm -f ginac_dummy
echo "done!"
