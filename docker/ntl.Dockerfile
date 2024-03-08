FROM voidlinux/voidlinux-musl:latest as base

ENV CFLAGS -march=x86-64 -O2
ENV CXXFLAGS $CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -yS xbps
RUN xbps-install -ySu
RUN xbps-install -yS autoconf gcc gmp-devel make wget


FROM base as ntl

RUN wget https://libntl.org/ntl-11.4.4.tar.gz
RUN tar xf ntl-11.4.4.tar.gz
WORKDIR /ntl-11.4.4/src
RUN ./configure
RUN make -j$(nproc)
RUN make install