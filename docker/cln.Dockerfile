FROM alpine:3.18.4 as base
LABEL author="Florian Frohn"
RUN apk add gcc g++ git automake autoconf make

FROM base as cln

RUN apk add texinfo

RUN git clone git://www.ginac.de/cln.git
WORKDIR /cln
RUN git checkout cln_1-3-6
RUN ./autogen.sh
RUN ./configure CXXFLAGS='-march=x86-64 -O3 -DNDEBUG' CFLAGS='-march=x86-64 -O3 -DNDEBUG'
RUN make -j$(nproc)
RUN make install
