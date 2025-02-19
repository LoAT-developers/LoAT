ARG PLATFORM=linux/arm64
FROM --platform=${PLATFORM} voidlinux/voidlinux-musl:latest AS base

ENV CFLAGS=-march=x86-64 -O2
ENV CXXFLAGS=$CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -ySu xbps
RUN xbps-install -ySu
RUN xbps-install -yS autoconf gcc make


FROM base AS gmp

RUN xbps-install -yS lzip wget

RUN wget https://ftp.gnu.org/gnu/gmp/gmp-6.2.1.tar.lz
RUN lzip -d gmp-6.2.1.tar.lz
RUN tar xf gmp-6.2.1.tar
WORKDIR /gmp-6.2.1
RUN ./configure ABI=64 CFLAGS="$CFLAGS -fPIC" CPPFLAGS="$CXXFLAGS -DPIC" --host=x86_64-pc-linux-gnu --enable-cxx --prefix /gmp/
RUN make -j$(nproc)
RUN make -j$(nproc) check
RUN make install



FROM base AS yices

RUN xbps-install -yS git gmp-devel gperf

COPY --from=gmp /gmp /gmp

COPY ../docker/loat-base-image/usr/local/lib/libpoly.a /usr/local/lib/
COPY ../docker/loat-base-image/usr/local/include/poly /usr/local/include/poly

COPY ../docker/loat-base-image/usr/local/lib/libcudd.a /usr/local/lib/libcudd.a
COPY ../docker/loat-base-image/usr/local/include/cudd.h /usr/local/include/cudd.h

RUN git clone https://github.com/SRI-CSL/yices2.git
WORKDIR /yices2
RUN git checkout 0ef16375
RUN autoconf
RUN ./configure --enable-mcsat --with-pic-gmp=/gmp/lib/libgmp.a
RUN make -j$(nproc)
RUN make -j$(nproc) static-lib
RUN make install
