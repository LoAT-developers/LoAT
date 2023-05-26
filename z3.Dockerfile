FROM loat/base:latest
LABEL author="Florian Frohn"

RUN wget https://github.com/Z3Prover/z3/archive/refs/tags/z3-4.9.1.tar.gz
RUN tar xf z3-4.9.1.tar.gz
WORKDIR /z3-z3-4.9.1
RUN mkdir build
WORKDIR /z3-z3-4.9.1/build
RUN cmake -DZ3_BUILD_LIBZ3_SHARED=FALSE -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG" ..
RUN make -j
RUN make install
