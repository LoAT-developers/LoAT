#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target cvc5 -t cvc5 -f ../docker/cvc5.Dockerfile ..
echo "create..."
docker create -ti --name cvc5_dummy cvc5 sh
echo "cp..."
docker cp cvc5_dummy:/usr/local/include/cvc5 $DEST/include/cvc5
docker cp cvc5_dummy:/usr/local/lib64/libcvc5.a $DEST/lib
docker cp cvc5_dummy:/usr/local/lib64/libcadical.a $DEST/lib
echo "rm..."
docker rm -f cvc5_dummy
echo "done!"

