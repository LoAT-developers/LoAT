FROM loat/base:latest
LABEL author="Florian Frohn"

RUN git clone https://github.com/ivmai/cudd.git
WORKDIR /cudd
# make check fails when compiled with -DNDEBUG
RUN ./configure CFLAGS='-fPIC -march=sandybridge -O3' CXXFLAGS='-fPIC -march=sandybridge -O3'
RUN sed -i 's/aclocal-1.14/aclocal-1.16/g' Makefile
RUN sed -i 's/automake-1.14/automake-1.16/g' Makefile
RUN make -j
RUN make -j check
RUN make install
