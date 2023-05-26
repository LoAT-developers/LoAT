FROM loat/base:latest
LABEL author="Florian Frohn"

RUN xbps-install -yS gmp-devel

RUN wget https://libntl.org/ntl-11.4.4.tar.gz
RUN tar xf ntl-11.4.4.tar.gz
WORKDIR /ntl-11.4.4/src
RUN ./configure CXXFLAGS='-march=sandybridge -O3 -DNDEBUG'
RUN make -j
RUN make install
