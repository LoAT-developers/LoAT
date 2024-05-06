FROM alpine:3.18.4 as base

ENV CFLAGS -march=x86-64 -O2 -DNDEBUG
ENV CXXFLAGS $CFLAGS

RUN apk add gcc git make musl-dev perl gmp-dev mpfr-dev

FROM base as elina

RUN git clone https://github.com/LoAT-developers/ELINA.git
WORKDIR /ELINA
RUN ./configure
RUN make -j$(nproc)
RUN make install
