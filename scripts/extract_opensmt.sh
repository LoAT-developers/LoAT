#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target opensmt -t opensmt -f ../docker/opensmt.Dockerfile .
echo "create..."
docker create -ti --name opensmt_dummy opensmt sh
echo "cp..."
docker cp opensmt_dummy:/usr/local/lib/libopensmt.a $DEST/lib
docker cp opensmt_dummy:/usr/local/include/opensmt $DEST/include/opensmt
echo "rm..."
docker rm -f opensmt_dummy
echo "done!"
