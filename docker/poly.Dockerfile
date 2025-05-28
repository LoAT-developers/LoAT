ARG PLATFORM=linux/arm64
FROM --platform=${PLATFORM} voidlinux/voidlinux-musl:latest AS base

ENV CFLAGS=-march=x86-64 -O2
ENV CXXFLAGS=$CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -yS xbps
RUN xbps-install -ySu
RUN xbps-install -yS cmake gcc gmpxx-devel make wget python-devel


FROM base AS poly

RUN xbps-install -yS 

RUN wget https://github.com/SRI-CSL/libpoly/archive/refs/tags/v0.1.13.tar.gz
RUN tar xf v0.1.13.tar.gz
WORKDIR /libpoly-0.1.13/build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_POSITION_INDEPENDENT_CODE=ON ..
RUN make -j$(nproc)
RUN make install