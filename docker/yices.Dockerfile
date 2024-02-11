FROM voidlinux/voidlinux-musl:latest as base

ENV CFLAGS -march=x86-64 -O2
ENV CXXFLAGS $CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -ySu xbps
RUN xbps-install -ySu
RUN xbps-install -yS autoconf gcc make


FROM base as gmp

RUN xbps-install -yS lzip wget

RUN wget https://gmplib.org/download/gmp/gmp-6.2.1.tar.lz
RUN lzip -d gmp-6.2.1.tar.lz
RUN tar xf gmp-6.2.1.tar
WORKDIR /gmp-6.2.1
RUN ./configure ABI=64 CFLAGS="$CFLAGS -fPIC" CPPFLAGS="$CXXFLAGS -DPIC" --host=x86_64-pc-linux-gnu --enable-cxx --prefix /gmp/
RUN make -j
RUN make -j check
RUN make install



FROM base as yices

RUN xbps-install -yS git gmp-devel gperf

COPY --from=gmp /gmp /gmp

COPY ../lib/libpoly.a /usr/local/lib/
COPY ../include/poly /usr/local/include/poly

COPY ../lib/libcudd.a /usr/local/lib/libcudd.a
COPY ../include/cudd.h /usr/local/include/cudd.h

RUN git clone https://github.com/SRI-CSL/yices2.git
WORKDIR /yices2
RUN autoconf
RUN ./configure --enable-mcsat --with-pic-gmp=/gmp/lib/libgmp.a
RUN make -j
RUN make -j static-lib
RUN make install
