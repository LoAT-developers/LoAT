#!/bin/bash
DEST=../docker/loat-base-image/usr/local
echo "build..."
docker build --target elina -t elina -f ../docker/elina.Dockerfile .
echo "create..."
docker create -ti --name elina_dummy elina sh
echo "cp..."
docker cp elina_dummy:/usr/local/lib/liboptpoly.a $DEST/lib
docker cp elina_dummy:/usr/local/lib/liboptoct.a $DEST/lib
docker cp elina_dummy:/usr/local/lib/libelinalinearize.a $DEST/lib
docker cp elina_dummy:/usr/local/lib/libelinaux.a $DEST/lib
docker cp elina_dummy:/usr/local/lib/liboptzones.a $DEST/lib
docker cp elina_dummy:/usr/local/lib/libpartitions.a $DEST/lib
docker cp elina_dummy:/usr/local/include/elina_config.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_scalar.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_interval.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_coeff.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_dimension.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_linexpr0.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_lincons0.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_manager.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_abstract0.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_texpr0.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_tcons0.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_generic.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_scalar_arith.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_interval_arith.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_coeff_arith.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_linexpr0_arith.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_linearize.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_linearize_texpr.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_rat.h $DEST/include
docker cp elina_dummy:/usr/local/include/elina_int.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_oct.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_oct_internal.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_oct_hmat.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_oct_closure_comp_sparse.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_oct_incr_closure_comp_sparse.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_oct_closure_dense_scalar.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_oct_incr_closure_dense_scalar.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_mf_qsort.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_pk_matrix.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_pk_internal.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_pk_test.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_pk_config.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_pk.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_zones.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_zones_internal.h $DEST/include
docker cp elina_dummy:/usr/local/include/opt_mat.h $DEST/include
docker cp elina_dummy:/usr/local/include/comp_list.h $DEST/include
echo "rm..."
docker rm -f elina_dummy
echo "done!"
