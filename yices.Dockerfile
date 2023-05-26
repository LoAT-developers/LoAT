FROM loat/base:latest
LABEL author="Florian Frohn"

RUN xbps-install -yS gperf gmp-devel

COPY --from=loat/gmp /gmp /gmp

COPY --from=loat/poly /usr/local/lib/libpoly.a /usr/local/lib/
COPY --from=loat/poly /usr/local/include/poly /usr/local/include/poly

COPY --from=loat/cudd /usr/local/lib/libcudd.a /usr/local/lib/libcudd.a
COPY --from=loat/cudd /usr/local/include/cudd.h /usr/local/include/cudd.h

RUN git clone https://github.com/SRI-CSL/yices2.git
WORKDIR /yices2
RUN autoconf
RUN ./configure --enable-mcsat --with-pic-gmp=/gmp/lib/libgmp.a CFLAGS='-march=sandybridge -O3 -DNDEBUG'
RUN make -j
RUN make -j static-lib
RUN make install
