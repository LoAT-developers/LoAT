#!/bin/bash
echo "build..."
docker build --target poly -t poly -f ../docker/poly.Dockerfile .
echo "create..."
docker create -ti --name poly_dummy poly sh
echo "cp..."
docker cp poly_dummy:/usr/local/lib/libpoly.a ../lib
docker cp poly_dummy:/usr/local/lib/libpolyxx.a ../lib
docker cp poly_dummy:/usr/local/include/poly/ ../include
echo "rm..."
docker rm -f poly_dummy
echo "done!"

