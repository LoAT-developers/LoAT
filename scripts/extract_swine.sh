#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target swine -t swine -f ../docker/swine.Dockerfile ..
echo "create..."
docker create -ti --name swine_dummy swine sh
echo "cp..."
mkdir -p $DEST/include/swine
docker cp swine_dummy:/swine-z3/include/config.h $DEST/include/swine
docker cp swine_dummy:/swine-z3/include/lemma_kind.h $DEST/include/swine
docker cp swine_dummy:/swine-z3/include/preproc_kind.h $DEST/include/swine
docker cp swine_dummy:/swine-z3/include/swine.h $DEST/include/swine
docker cp swine_dummy:/swine-z3/include/version.h $DEST/include/swine
docker cp swine_dummy:/swine-z3/libswine-z3.a $DEST/lib
echo "rm..."
docker rm -f swine_dummy
echo "done!"

