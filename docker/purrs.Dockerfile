FROM voidlinux/voidlinux-musl:latest as base

ENV CFLAGS -march=x86-64 -O2
ENV CXXFLAGS $CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -yS xbps
RUN xbps-install -ySu
RUN xbps-install -yS autoconf automake cln-devel gcc git gmpxx-devel libtool make readline-devel


FROM base as purrs

COPY ../lib/libginac.a /usr/local/lib64/libginac.a
COPY ../include/ginac /usr/local/include/ginac

COPY ../include/NTL /usr/local/include/NTL
COPY ../lib/libntl.a /usr/local/lib/libntl.a

RUN git clone https://github.com/aprove-developers/LoAT-purrs.git
WORKDIR /LoAT-purrs
RUN autoreconf --install
RUN automake
RUN ./configure
RUN make -j
RUN make install