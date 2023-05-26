FROM loat/base:latest
LABEL author="Florian Frohn"

RUN xbps-install -yS lzip

# position-independent gmp
RUN wget https://gmplib.org/download/gmp/gmp-6.2.1.tar.lz
RUN lzip -d gmp-6.2.1.tar.lz
RUN tar xf gmp-6.2.1.tar
WORKDIR /gmp-6.2.1
RUN ./configure ABI=64 CFLAGS="-fPIC -O3 -DNDEBUG" CPPFLAGS="-DPIC -O3 -DNDEBUG" --host=sandybridge-pc-linux-gnu --enable-cxx --prefix /gmp/
RUN make -j
RUN make -j check
RUN make install
