#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target faudes -t faudes -f ../docker/faudes.Dockerfile .
echo "create..."
docker create -ti --name faudes_dummy faudes sh
echo "cp..."
docker cp faudes_dummy:/usr/local/lib/libfaudes.a $DEST/lib
docker cp faudes_dummy:/usr/local/include/faudes $DEST/include
echo "rm..."
docker rm -f faudes_dummy
echo "done!"
