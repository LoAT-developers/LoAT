#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target z3 -t z3 -f ../docker/z3.Dockerfile ..
echo "create..."
docker create -ti --name z3_dummy z3 sh
echo "cp..."
docker cp z3_dummy:/usr/local/include/z3_algebraic.h $DEST/include
docker cp z3_dummy:/usr/local/include/z3_api.h $DEST/include
docker cp z3_dummy:/usr/local/include/z3_ast_containers.h $DEST/include
docker cp z3_dummy:/usr/local/include/z3_fixedpoint.h $DEST/include
docker cp z3_dummy:/usr/local/include/z3_fpa.h $DEST/include
docker cp z3_dummy:/usr/local/include/z3.h $DEST/include
docker cp z3_dummy:/usr/local/include/z3++.h $DEST/include
docker cp z3_dummy:/usr/local/include/z3_macros.h $DEST/include
docker cp z3_dummy:/usr/local/include/z3_optimization.h $DEST/include
docker cp z3_dummy:/usr/local/include/z3_polynomial.h $DEST/include
docker cp z3_dummy:/usr/local/include/z3_rcf.h $DEST/include
docker cp z3_dummy:/usr/local/include/z3_spacer.h $DEST/include
docker cp z3_dummy:/usr/local/include/z3_v1.h $DEST/include
docker cp z3_dummy:/usr/local/include/z3_version.h $DEST/include
docker cp z3_dummy:/usr/local/lib64/libz3.a $DEST/lib
echo "rm..."
docker rm -f z3_dummy
echo "done!"

