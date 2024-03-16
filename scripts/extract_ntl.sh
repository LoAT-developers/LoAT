#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target ntl -t ntl -f ../docker/ntl.Dockerfile .
echo "create..."
docker create -ti --name ntl_dummy ntl sh
echo "cp..."
docker cp ntl_dummy:/usr/local/lib/libntl.a $DEST/lib
docker cp ntl_dummy:/usr/local/include/NTL/ $DEST/include
echo "rm..."
docker rm -f ntl_dummy
echo "done!"
