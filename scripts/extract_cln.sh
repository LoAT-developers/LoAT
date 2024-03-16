#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target cln -t cln -f ../docker/cln.Dockerfile .
echo "create..."
docker create -ti --name cln_dummy cln sh
echo "cp..."
docker cp cln_dummy:/usr/local/lib/libcln.a $DEST/lib
docker cp cln_dummy:/usr/local/include/cln/ $DEST/include
echo "rm..."
docker rm -f cln_dummy
echo "done!"
