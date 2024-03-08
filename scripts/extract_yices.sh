#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target yices -t yices -f ../docker/yices.Dockerfile ..
echo "create..."
docker create -ti --name yices_dummy yices sh
echo "cp..."
docker cp yices_dummy:/usr/local/include/yices.h $DEST/include
docker cp yices_dummy:/usr/local/include/yices_exit_codes.h $DEST/include
docker cp yices_dummy:/usr/local/include/yices_limits.h $DEST/include
docker cp yices_dummy:/usr/local/include/yices_types.h $DEST/include
docker cp yices_dummy:/usr/local/lib/libyices.a $DEST/lib
echo "rm..."
docker rm -f yices_dummy
echo "done!"

