FROM voidlinux/voidlinux-musl:latest as base

ENV CFLAGS -march=x86-64 -O2
ENV CXXFLAGS $CFLAGS

RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -ySu xbps
RUN xbps-install -ySu
RUN xbps-install -ySu gcc git cmake make gmp-devel mpfr-devel

FROM base as crab

### needed for elina
COPY ../docker/loat-base-image/usr/local/lib/liboptpoly.a /usr/local/lib/
COPY ../docker/loat-base-image/usr/local/lib/liboptoct.a /usr/local/lib/
COPY ../docker/loat-base-image/usr/local/lib/libelinalinearize.a /usr/local/lib/
COPY ../docker/loat-base-image/usr/local/lib/libelinaux.a /usr/local/lib/
COPY ../docker/loat-base-image/usr/local/lib/liboptzones.a /usr/local/lib/
COPY ../docker/loat-base-image/usr/local/lib/libpartitions.a /usr/local/lib/
COPY ../docker/loat-base-image/usr/local/include/elina_config.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_scalar.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_interval.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_coeff.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_dimension.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_linexpr0.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_lincons0.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_manager.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_abstract0.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_texpr0.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_tcons0.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_generic.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_scalar_arith.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_interval_arith.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_coeff_arith.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_linexpr0_arith.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_linearize.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_linearize_texpr.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_rat.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/elina_int.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_oct.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_oct_internal.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_oct_hmat.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_oct_closure_comp_sparse.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_oct_incr_closure_comp_sparse.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_oct_closure_dense_scalar.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_oct_incr_closure_dense_scalar.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_mf_qsort.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_pk_matrix.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_pk_internal.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_pk_test.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_pk_config.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_pk.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_zones.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_zones_internal.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/opt_mat.h /usr/local/include/
COPY ../docker/loat-base-image/usr/local/include/comp_list.h /usr/local/include/

RUN git clone https://github.com/LoAT-developers/crab.git
# WORKDIR crab
# RUN git checkout v2.0
RUN mkdir /crab/build
WORKDIR /crab/build

RUN xbps-install -ySu boost-devel
### needed for apron
# RUN xbps-install -ySu gmpxx-devel
### needed for pplite
# RUN xbps-install -ySu flintlib-devel

RUN cmake -DCRAB_USE_ELINA=ON -DELINA_ROOT=/usr/local -DCMAKE_INSTALL_PREFIX=/tmp/ ..
### needed for apron
# RUN cmake -DCRAB_USE_APRON=ON -DCMAKE_INSTALL_PREFIX=/tmp/ ..
# RUN cmake --build . -j$(nproc) --target apron && cmake /crab
RUN make -j$(nproc)
RUN make install

### needed for apron
# RUN xbps-install tar
# WORKDIR /tmp/apron/lib
# RUN tar -cf apron_lib.tar *
# WORKDIR /tmp/apron/include
# RUN tar -cf apron_include.tar *
