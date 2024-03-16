FROM voidlinux/voidlinux-musl:latest as base

ENV CFLAGS -march=x86-64 -O2
ENV CXXFLAGS $CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -yS xbps
RUN xbps-install -ySu
RUN xbps-install -yS cln-devel cmake gcc git make python-devel


FROM base as ginac

RUN git clone git://www.ginac.de/ginac.git
WORKDIR /ginac
RUN git checkout release_1-8-7
RUN mkdir build
WORKDIR /ginac/build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=false ..
RUN make -j$(nproc)
RUN make install
