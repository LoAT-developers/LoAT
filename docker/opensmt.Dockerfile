FROM voidlinux/voidlinux-musl:latest as base

ENV CFLAGS -march=x86-64 -O2
ENV CXXFLAGS $CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -yS xbps
RUN xbps-install -ySu
RUN xbps-install -yS cmake gcc git make gmp-devel gmpxx-devel
RUN xbps-install -yS bison flex


FROM base as opensmt

RUN git clone https://github.com/usi-verification-and-security/opensmt.git
WORKDIR /opensmt
RUN make -j CMAKE_FLAGS=-DBUILD_EXECUTABLES:BOOL=OFF install

