ARG PLATFORM=linux/arm64
FROM --platform=${PLATFORM} voidlinux/voidlinux-musl:latest AS base

ENV CFLAGS=-march=x86-64 -O2
ENV CXXFLAGS=$CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -ySu xbps
RUN xbps-install -ySu
RUN xbps-install -yS bash boost-devel cmake gcc git make


FROM base AS swine

COPY ../docker/loat-base-image/usr/local/lib/libz3.a /usr/local/lib/
COPY ../docker/loat-base-image/usr/local/include/ /usr/local/include/

RUN git clone https://github.com/ffrohn/swine-z3
WORKDIR /swine-z3/scripts
RUN git checkout fdda2328
RUN ./configure_and_build.sh