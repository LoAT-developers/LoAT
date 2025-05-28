ARG PLATFORM=linux/arm64
FROM --platform=${PLATFORM} voidlinux/voidlinux-musl:latest AS base

ENV CFLAGS=-march=x86-64 -O2=-DNDEBUG
ENV CXXFLAGS=$CFLAGS

ENV CFLAGS=-march=x86-64 -O2
ENV CXXFLAGS=$CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -ySu xbps
RUN xbps-install -ySu
RUN xbps-install -yS gcc git make perl gmp-devel mpfr-devel

FROM base AS elina

RUN git clone https://github.com/LoAT-developers/ELINA.git
WORKDIR /ELINA
RUN ./configure
RUN make -j$(nproc)
RUN make install
