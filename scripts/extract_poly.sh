#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target poly -t poly -f ../docker/poly.Dockerfile .
echo "create..."
docker create -ti --name poly_dummy poly sh
echo "cp..."
docker cp poly_dummy:/usr/local/lib/libpoly.a $DEST/lib
docker cp poly_dummy:/usr/local/lib/libpolyxx.a $DEST/lib
docker cp poly_dummy:/usr/local/include/poly/ $DEST/include
echo "rm..."
docker rm -f poly_dummy
echo "done!"

