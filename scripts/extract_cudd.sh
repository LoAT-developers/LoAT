#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target cudd -t cudd -f ../docker/cudd.Dockerfile .
echo "create..."
docker create -ti --name cudd_dummy cudd sh
echo "cp..."
docker cp cudd_dummy:/usr/local/lib/libcudd.a $DEST/lib
docker cp cudd_dummy:/usr/local/include/cudd.h $DEST/include
echo "rm..."
docker rm -f cudd_dummy
echo "done!"
