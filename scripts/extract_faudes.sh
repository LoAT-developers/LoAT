#!/bin/bash
echo "build..."
docker build --target faudes -t faudes -f ../docker/faudes.Dockerfile .
echo "create..."
docker create -ti --name faudes_dummy faudes sh
echo "cp..."
docker cp faudes_dummy:/usr/local/lib/libfaudes.a ../lib
docker cp faudes_dummy:/usr/local/include/faudes ../include
echo "rm..."
docker rm -f faudes_dummy
echo "done!"
