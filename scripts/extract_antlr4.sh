#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target antlr4 -t antlr4 -f ../docker/antlr4.Dockerfile .
echo "create..."
docker create -ti --name antlr4_dummy antlr4 sh
echo "cp..."
docker cp antlr4_dummy:/usr/local/lib/libantlr4-runtime.a $DEST/lib
docker cp antlr4_dummy:/usr/local/include/antlr4-runtime $DEST/include
mv $DEST/include/antlr4-runtime/* $DEST/include/
rm -r $DEST/include/antlr4-runtime
echo "rm..."
docker rm -f antlr4_dummy
echo "done!"
