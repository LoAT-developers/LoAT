#!/bin/bash
echo "build..."
docker build --target z3 -t z3 -f ../docker/z3.Dockerfile ..
echo "create..."
docker create -ti --name z3_dummy z3 sh
echo "cp..."
docker cp z3_dummy:/usr/local/include/z3_algebraic.h ../include
docker cp z3_dummy:/usr/local/include/z3_api.h ../include
docker cp z3_dummy:/usr/local/include/z3_ast_containers.h ../include
docker cp z3_dummy:/usr/local/include/z3_fixedpoint.h ../include
docker cp z3_dummy:/usr/local/include/z3_fpa.h ../include
docker cp z3_dummy:/usr/local/include/z3.h ../include
docker cp z3_dummy:/usr/local/include/z3++.h ../include
docker cp z3_dummy:/usr/local/include/z3_macros.h ../include
docker cp z3_dummy:/usr/local/include/z3_optimization.h ../include
docker cp z3_dummy:/usr/local/include/z3_polynomial.h ../include
docker cp z3_dummy:/usr/local/include/z3_rcf.h ../include
docker cp z3_dummy:/usr/local/include/z3_spacer.h ../include
docker cp z3_dummy:/usr/local/include/z3_v1.h ../include
docker cp z3_dummy:/usr/local/include/z3_version.h ../include
docker cp z3_dummy:/usr/local/lib64/libz3.a ../lib
echo "rm..."
docker rm -f z3_dummy
echo "done!"

