#!/bin/bash
echo "build..."
docker build --target swine -t swine --no-cache-filter swine -f ../docker/swine.Dockerfile ..
echo "create..."
docker create -ti --name swine_dummy swine sh
echo "cp..."
mkdir -p ../include/swine
docker cp swine_dummy:/swine-z3/include/config.h ../include/swine
docker cp swine_dummy:/swine-z3/include/lemma_kind.h ../include/swine
docker cp swine_dummy:/swine-z3/include/preproc_kind.h ../include/swine
docker cp swine_dummy:/swine-z3/include/swine.h ../include/swine
docker cp swine_dummy:/swine-z3/build/libswine-z3.a ../lib
echo "rm..."
docker rm -f swine_dummy
echo "done!"

