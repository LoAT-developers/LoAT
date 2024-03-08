#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target purrs -t purrs -f ../docker/purrs.Dockerfile ..
echo "create..."
docker create -ti --name purrs_dummy purrs sh
echo "cp..."
docker cp purrs_dummy:/usr/local/lib/libpurrs.a $DEST/lib
docker cp purrs_dummy:/usr/local/include/purrs.hh $DEST/include
echo "rm..."
docker rm -f purrs_dummy
echo "done!"

