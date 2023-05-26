FROM loat/base:latest
LABEL author="Florian Frohn"

RUN xbps-install -yS cln-devel

RUN wget https://www.ginac.de/ginac-1.8.6.tar.bz2
RUN tar xf ginac-1.8.6.tar.bz2
WORKDIR /ginac-1.8.6
RUN mkdir build
WORKDIR /ginac-1.8.6/build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=false -DCMAKE_C_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG" -DCMAKE_CXX_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG" ..
RUN make -j
RUN make install
