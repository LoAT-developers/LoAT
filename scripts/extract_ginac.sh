#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target ginac -t ginac -f ../docker/ginac.Dockerfile .
echo "create..."
docker create -ti --name ginac_dummy ginac sh
echo "cp..."
docker cp ginac_dummy:/usr/local/lib64/libginac.a $DEST/lib
docker cp ginac_dummy:/usr/local/include/ginac $DEST/include
echo "rm..."
docker rm -f ginac_dummy
echo "done!"
