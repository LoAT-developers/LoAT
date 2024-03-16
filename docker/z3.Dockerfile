FROM voidlinux/voidlinux-musl:latest as base

ENV CFLAGS -march=x86-64 -O2
ENV CXXFLAGS $CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -ySu xbps
RUN xbps-install -ySu
RUN xbps-install -yS cmake gcc make wget python3-devel


FROM base as z3

RUN wget https://github.com/Z3Prover/z3/archive/refs/tags/z3-4.12.5.tar.gz
RUN tar xf z3-4.12.5.tar.gz
WORKDIR /z3-z3-4.12.5
RUN mkdir build
WORKDIR /z3-z3-4.12.5/build
RUN cmake -DZ3_BUILD_LIBZ3_SHARED=FALSE -DCMAKE_BUILD_TYPE=Release ..
RUN make -j$(nproc)
RUN make install

# for building a binary

# RUN wget https://github.com/Z3Prover/z3/archive/refs/tags/z3-4.12.5.tar.gz
# RUN tar xf z3-4.12.5.tar.gz
# WORKDIR /z3-z3-4.12.5
# RUN python scripts/mk_make.py --staticbin
# WORKDIR /z3-z3-4.12.5/build
# RUN make -j$(nproc)
# RUN make install