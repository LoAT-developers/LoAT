ARG PLATFORM=linux/arm64
FROM --platform=${PLATFORM} voidlinux/voidlinux-musl:latest AS base

ENV CFLAGS=-march=x86-64 -O2=-fPIC
ENV CXXFLAGS=$CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -ySu xbps
RUN xbps-install -ySu
RUN xbps-install -yS bash gcc cmake make git

RUN xbps-install -yS m4
RUN xbps-install -yS boost-devel
RUN xbps-install -yS bison
RUN xbps-install -yS patch
RUN xbps-install -yS libexecinfo-devel

FROM base AS smtrat

ARG CACHE_BUMP=0

RUN git clone https://github.com/ffrohn/smtrat.git
WORKDIR ./smtrat
RUN mkdir build
WORKDIR ./build
RUN cmake -DCLI_ENABLE_QUANTIFIER_ELIMINATION=1 ..
RUN make -j4 smtrat-static

RUN xbps-install -ySu zip

WORKDIR ../src
RUN find . -wholename './smtrat-*/*.h' | xargs zip ../headers.zip

