#!/bin/bash
echo "build..."
docker build --target yices -t yices -f ../docker/yices.Dockerfile ..
echo "create..."
docker create -ti --name yices_dummy yices sh
echo "cp..."
docker cp yices_dummy:/usr/local/include/yices.h ../include
docker cp yices_dummy:/usr/local/include/yices_exit_codes.h ../include
docker cp yices_dummy:/usr/local/include/yices_limits.h ../include
docker cp yices_dummy:/usr/local/include/yices_types.h ../include
docker cp yices_dummy:/usr/local/lib/libyices.a ../lib
echo "rm..."
docker rm -f yices_dummy
echo "done!"

