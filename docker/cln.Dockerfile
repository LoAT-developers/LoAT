FROM voidlinux/voidlinux-musl:latest as base

ENV CFLAGS -march=x86-64 -O2 -DNDEBUG
ENV CXXFLAGS $CFLAGS

ENV CFLAGS -march=x86-64 -O2
ENV CXXFLAGS $CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -ySu xbps
RUN xbps-install -ySu
RUN xbps-install -yS gcc git automake autoconf make texinfo wget

FROM base as cln

RUN git clone git://www.ginac.de/cln.git
WORKDIR /cln
RUN git checkout cln_1-3-6
RUN ./autogen.sh
RUN ./configure CXXFLAGS='-march=x86-64 -O3 -DNDEBUG' CFLAGS='-march=x86-64 -O3 -DNDEBUG'
RUN make -j$(nproc)
RUN make install
