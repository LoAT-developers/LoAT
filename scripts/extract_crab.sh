#!/bin/bash
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
DEST=$SCRIPT_DIR/../docker/loat-base-image/usr/local
echo "build..."
docker build --target crab -t crab -f $SCRIPT_DIR/../docker/crab.Dockerfile $SCRIPT_DIR/..
echo "create..."
docker create -ti --name crab_dummy crab sh
echo "cp..."
docker cp crab_dummy:/tmp/crab/lib/libCrab.a $DEST/lib/
docker cp crab_dummy:/tmp/crab/include/crab $DEST/include/
### needed for apron
# docker cp crab_dummy:/tmp/apron/lib/apron_lib.tar $DEST/lib/
# docker cp crab_dummy:/tmp/apron/include/apron_include.tar $DEST/include/
# echo "untar..."
# cd $DEST/lib/
# tar xf apron_lib.tar
# cd $DEST/include/
# tar xf apron_include.tar
echo "rm..."
docker rm -f crab_dummy
echo "done!"
