FROM voidlinux/voidlinux-musl:latest as base

ENV CFLAGS -march=x86-64 -O2
ENV CXXFLAGS $CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -yS xbps
RUN xbps-install -ySu
RUN xbps-install -yS autoconf automake cln-devel gcc git gmpxx-devel libtool make readline-devel


FROM base as purrs

COPY ../docker/loat-base-image/usr/local/lib/libginac.a /usr/local/lib64/libginac.a
COPY ../docker/loat-base-image/usr/local/include/ginac /usr/local/include/ginac

COPY ../docker/loat-base-image/usr/local/include/NTL /usr/local/include/NTL
COPY ../docker/loat-base-image/usr/local/lib/libntl.a /usr/local/lib/libntl.a

RUN git clone https://github.com/aprove-developers/LoAT-purrs.git
WORKDIR /LoAT-purrs
RUN git checkout 1dadc7d
RUN autoreconf --install
RUN automake
RUN ./configure
RUN make -j$(nproc)
RUN make install