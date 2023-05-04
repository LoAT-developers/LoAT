FROM voidlinux/voidlinux-musl:latest as loat_build
LABEL author="Florian Frohn"

ARG CACHEBUST=1

RUN xbps-install -ySu xbps
RUN xbps-install -yS
RUN xbps-install -yu
RUN xbps-install -y gcc
RUN xbps-install -y git
RUN xbps-install -y automake
RUN xbps-install -y autoconf
RUN xbps-install -y make
RUN xbps-install -y cmake
RUN xbps-install -y lzip
RUN xbps-install -y wget
RUN xbps-install -y gperf
RUN xbps-install -y libtool
RUN xbps-install -y readline-devel
RUN xbps-install -y cln-devel
RUN xbps-install -y pkg-config
RUN xbps-install -y boost-devel
RUN xbps-install -y giac-devel
RUN xbps-install -y python-devel

RUN mkdir /src/

# reduce
RUN xbps-install -y subversion
RUN xbps-install -y ncurses-devel
RUN xbps-install -y libX11-devel
RUN xbps-install -y libXft-devel
RUN xbps-install -y libXext-devel
RUN xbps-install -y file
RUN xbps-install -y libffi-devel
RUN xbps-install -y libltdl-devel
WORKDIR /src
RUN svn co -r 6325 http://svn.code.sf.net/p/reduce-algebra/code/trunk reduce-algebra
WORKDIR /src/reduce-algebra
RUN ./configure --with-csl
RUN cp /usr/include/unistd.h /usr/include/sys/
RUN make
WORKDIR /src/reduce-algebra/generic/libreduce
RUN sed -i 's/AC_CONFIG_MACRO_DIRS/AC_CONFIG_MACRO_DIR/g' src/configure.ac
RUN xbps-alternatives -g python -s python
RUN make

# z3
WORKDIR /src
RUN wget https://github.com/Z3Prover/z3/archive/refs/tags/z3-4.9.1.tar.gz
RUN tar xf z3-4.9.1.tar.gz
WORKDIR /src/z3-z3-4.9.1
RUN mkdir build
WORKDIR /src/z3-z3-4.9.1/build
RUN cmake -DZ3_BUILD_LIBZ3_SHARED=FALSE -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG" ..
RUN make -j
RUN make install

# position-independent gmp
WORKDIR /src
RUN wget https://gmplib.org/download/gmp/gmp-6.2.1.tar.lz
RUN lzip -d gmp-6.2.1.tar.lz
RUN tar xf gmp-6.2.1.tar
WORKDIR /src/gmp-6.2.1
RUN ./configure ABI=64 CFLAGS="-fPIC -O3 -DNDEBUG" CPPFLAGS="-DPIC -O3 -DNDEBUG" --host=sandybridge-pc-linux-gnu --enable-cxx --prefix /gmp/
RUN make -j
RUN make -j check
RUN make install

RUN xbps-install -y gmp-devel gmpxx-devel

# libpoly
WORKDIR /src
RUN git clone https://github.com/SRI-CSL/libpoly.git
WORKDIR /src/libpoly/build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DCMAKE_C_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG" -DCMAKE_CXX_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG" ..
RUN make -j
RUN make install

# cudd
WORKDIR /src
RUN git clone https://github.com/ivmai/cudd.git
WORKDIR /src/cudd
# make check fails when compiled with -DNDEBUG
RUN ./configure CFLAGS='-fPIC -march=sandybridge -O3' CXXFLAGS='-fPIC -march=sandybridge -O3'
RUN sed -i 's/aclocal-1.14/aclocal-1.16/g' Makefile
RUN sed -i 's/automake-1.14/automake-1.16/g' Makefile
RUN make -j
RUN make -j check
RUN make install

# yices
WORKDIR /src
RUN git clone https://github.com/SRI-CSL/yices2.git
WORKDIR /src/yices2
RUN autoconf
RUN ./configure --enable-mcsat --with-pic-gmp=/gmp/lib/libgmp.a CFLAGS='-march=sandybridge -O3 -DNDEBUG'
RUN make -j
RUN make -j static-lib
RUN make install

# ginac
WORKDIR /src
RUN wget https://www.ginac.de/ginac-1.8.6.tar.bz2
RUN tar xf ginac-1.8.6.tar.bz2
WORKDIR /src/ginac-1.8.6
RUN mkdir build
WORKDIR /src/ginac-1.8.6/build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=false -DCMAKE_C_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG" -DCMAKE_CXX_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG" ..
RUN make -j
RUN make install

# ntl
WORKDIR /src
RUN wget https://libntl.org/ntl-11.4.4.tar.gz
RUN tar xf ntl-11.4.4.tar.gz
WORKDIR /src/ntl-11.4.4/src
RUN ./configure CXXFLAGS='-march=sandybridge -O3 -DNDEBUG'
RUN make -j
RUN make install

ARG CACHEBUST=2

# purrs
WORKDIR /src
RUN git clone https://github.com/aprove-developers/LoAT-purrs.git
WORKDIR /src/LoAT-purrs
RUN autoreconf --install
RUN automake
RUN ./configure --with-cxxflags='-march=sandybridge -O3 -DNDEBUG'
RUN make -j
RUN make install

RUN xbps-install -y apache-maven

# antlr4
WORKDIR /src
RUN git clone https://github.com/antlr/antlr4.git
WORKDIR /src/antlr4
RUN git checkout 4.11.1
RUN mkdir /src/antlr4/runtime/Cpp/build
WORKDIR /src/antlr4/runtime/Cpp/build
RUN cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_LIBDIR="/usr/local/lib" -DCMAKE_C_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG" -DCMAKE_CXX_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG"
RUN make -j
RUN make install

# faudes
WORKDIR /src
RUN wget https://fgdes.tf.fau.de/archive/libfaudes-2_30b.tar.gz
RUN tar xf libfaudes-2_30b.tar.gz
WORKDIR /src/libfaudes-2_30b
RUN xbps-install -y bash
RUN sed -i 's/MAINOPTS += -std=gnu++98 -D_GLIBCXX_USE_CXX11_ABI=0/MAINOPTS += -std=c++11/g' Makefile
RUN FAUDES_LINKING=static make -j

ARG ANTLR4_INCLUDE_PATH=/src/antlr4/runtime/Cpp/runtime/src
ARG SHA
ARG DIRTY
ARG BUILD_TYPE

# loat
RUN mkdir -p /src/LoAT
WORKDIR /src/LoAT
COPY CMakeLists.txt /src/LoAT/
COPY src /src/LoAT/src/
COPY --from=loat /src/LoAT/build /src/LoAT/build
RUN mkdir /src/LoAT/lib
RUN cp /src/reduce-algebra/generic/libreduce/x86_64-pc-linux-musl/libreduce.* /src/LoAT/lib
RUN cp /src/libfaudes-2_30b/libfaudes.* /src/LoAT/lib
RUN mkdir -p /src/LoAT/build/static/release
WORKDIR /src/LoAT/build/static/release
RUN cmake -DSTATIC=1 -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DCMAKE_C_FLAGS_RELEASE='-march=sandybridge -O3 -DNDEBUG' -DCMAKE_CXX_FLAGS_RELEASE='-march=sandybridge -O3 -DNDEBUG' -DSHA=$SHA -DDIRTY=$DIRTY ../../../
RUN make -j
