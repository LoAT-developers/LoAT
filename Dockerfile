FROM voidlinux/voidlinux-musl:latest as base
LABEL author="Florian Frohn"

RUN xbps-install -yS xbps
RUN xbps-install -ySu
RUN xbps-install -yS gcc git automake autoconf make cmake wget python-devel bash



FROM base as antlr4

RUN git clone https://github.com/antlr/antlr4.git
WORKDIR /antlr4
RUN git checkout 4.11.1
RUN mkdir /antlr4/runtime/Cpp/build
WORKDIR /antlr4/runtime/Cpp/build
RUN cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_LIBDIR="/usr/local/lib" -DCMAKE_C_FLAGS_RELEASE="-march=x86-64 -O3 -DNDEBUG" -DCMAKE_CXX_FLAGS_RELEASE="-march=x86-64 -O3 -DNDEBUG"
RUN make -j
RUN make install



FROM base as cudd

RUN git clone https://github.com/ivmai/cudd.git
WORKDIR /cudd
# make check fails when compiled with -DNDEBUG
RUN ./configure CFLAGS='-fPIC -march=x86-64 -O3' CXXFLAGS='-fPIC -march=x86-64 -O3'
RUN sed -i 's/aclocal-1.14/aclocal-1.16/g' Makefile
RUN sed -i 's/automake-1.14/automake-1.16/g' Makefile
RUN make -j
RUN make -j check
RUN make install



FROM base as faudes

RUN xbps-install -yS readline-devel

RUN wget https://fgdes.tf.fau.de/archive/libfaudes-2_30b.tar.gz
RUN tar xf libfaudes-2_30b.tar.gz
WORKDIR /libfaudes-2_30b
RUN sed -i 's/MAINOPTS += -std=gnu++98 -D_GLIBCXX_USE_CXX11_ABI=0/MAINOPTS += -std=c++11/g' Makefile
RUN FAUDES_LINKING=static make -j
RUN cp /libfaudes-2_30b/libfaudes.a /usr/local/lib/
RUN cp -r /libfaudes-2_30b/include /usr/local/include/faudes



FROM base as ginac

RUN xbps-install -yS cln-devel

RUN wget https://www.ginac.de/ginac-1.8.6.tar.bz2
RUN tar xf ginac-1.8.6.tar.bz2
WORKDIR /ginac-1.8.6
RUN mkdir build
WORKDIR /ginac-1.8.6/build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=false -DCMAKE_C_FLAGS_RELEASE="-march=x86-64 -O3 -DNDEBUG" -DCMAKE_CXX_FLAGS_RELEASE="-march=x86-64 -O3 -DNDEBUG" ..
RUN make -j
RUN make install



FROM base as gmp

RUN xbps-install -yS lzip

RUN wget https://gmplib.org/download/gmp/gmp-6.2.1.tar.lz
RUN lzip -d gmp-6.2.1.tar.lz
RUN tar xf gmp-6.2.1.tar
WORKDIR /gmp-6.2.1
RUN ./configure ABI=64 CFLAGS="-fPIC -O3 -DNDEBUG" CPPFLAGS="-DPIC -O3 -DNDEBUG" --host=x86_64-pc-linux-gnu --enable-cxx --prefix /gmp/
RUN make -j
RUN make -j check
RUN make install



FROM base as ntl

RUN xbps-install -yS gmp-devel

RUN wget https://libntl.org/ntl-11.4.4.tar.gz
RUN tar xf ntl-11.4.4.tar.gz
WORKDIR /ntl-11.4.4/src
RUN ./configure CXXFLAGS='-march=x86-64 -O3 -DNDEBUG'
RUN make -j
RUN make install



FROM base as poly

RUN xbps-install -yS gmpxx-devel

RUN git clone https://github.com/SRI-CSL/libpoly.git
WORKDIR /libpoly/build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DCMAKE_C_FLAGS_RELEASE="-march=x86-64 -O3 -DNDEBUG" -DCMAKE_CXX_FLAGS_RELEASE="-march=x86-64 -O3 -DNDEBUG" ..
RUN make -j
RUN make install



FROM base as purrs

RUN xbps-install -yS libtool gmpxx-devel cln-devel giac-devel

COPY --from=ginac /usr/local/lib64/libginac.a /usr/local/lib64/libginac.a
COPY --from=ginac /usr/local/include/ginac /usr/local/include/ginac

COPY --from=ntl /usr/local/include/NTL /usr/local/include/NTL
COPY --from=ntl /usr/local/lib/libntl.a /usr/local/lib/libntl.a

RUN git clone https://github.com/aprove-developers/LoAT-purrs.git
WORKDIR /LoAT-purrs
RUN autoreconf --install
RUN automake
RUN ./configure --with-cxxflags='-march=x86-64 -O3 -DNDEBUG'
RUN make -j
RUN make install



FROM base as yices

RUN xbps-install -yS gperf gmp-devel

COPY --from=gmp /gmp /gmp

COPY --from=poly /usr/local/lib/libpoly.a /usr/local/lib/
COPY --from=poly /usr/local/include/poly /usr/local/include/poly

COPY --from=cudd /usr/local/lib/libcudd.a /usr/local/lib/libcudd.a
COPY --from=cudd /usr/local/include/cudd.h /usr/local/include/cudd.h

RUN git clone https://github.com/SRI-CSL/yices2.git
WORKDIR /yices2
RUN autoconf
RUN ./configure --enable-mcsat --with-pic-gmp=/gmp/lib/libgmp.a CFLAGS='-march=x86-64 -O3 -DNDEBUG'
RUN make -j
RUN make -j static-lib
RUN make install



FROM base as z3

RUN wget https://github.com/Z3Prover/z3/archive/refs/tags/z3-4.9.1.tar.gz
RUN tar xf z3-4.9.1.tar.gz
WORKDIR /z3-z3-4.9.1
RUN mkdir build
WORKDIR /z3-z3-4.9.1/build
RUN cmake -DZ3_BUILD_LIBZ3_SHARED=FALSE -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE="-march=x86-64 -O3 -DNDEBUG" ..
RUN make -j
RUN make install



FROM base as loat

FROM loat/base:latest
LABEL author="Florian Frohn"

RUN xbps-install -yS boost-devel cln-devel gmp-devel

COPY --from=z3 /usr/local/lib64/libz3.a /usr/local/lib64/
COPY --from=z3 /usr/local/include/z3*.h /usr/local/include/

COPY --from=poly /usr/local/include/poly /usr/local/include/poly
COPY --from=poly /usr/local/lib/libpoly.a /usr/local/lib/

COPY --from=cudd /usr/local/include/cudd.h /usr/local/include/cudd.h
COPY --from=cudd /usr/local/lib/libcudd.a /usr/local/lib/libcudd.a

COPY --from=ntl /usr/local/include/NTL /usr/local/include/NTL
COPY --from=ntl /usr/local/lib/libntl.a /usr/local/lib/libntl.a

COPY --from=yices /usr/local/include/yices*.h /usr/local/include/
COPY --from=yices /usr/local/lib/libyices.a /usr/local/lib/libyices.a

COPY --from=ginac /usr/local/lib64/libginac.a /usr/local/lib64/libginac.a
COPY --from=ginac /usr/local/include/ginac /usr/local/include/ginac

COPY --from=purrs /usr/local/lib/libpurrs.a /usr/local/lib/libpurrs.a
COPY --from=purrs /usr/local/include/purrs.hh /usr/local/include/purrs.hh

COPY --from=antlr4 /usr/local/lib/libantlr4-runtime.a /usr/local/lib/libantlr4-runtime.a
COPY --from=antlr4 /usr/local/include/antlr4-runtime/ /usr/local/include/

COPY --from=faudes /usr/local/lib/libfaudes.a /usr/local/lib/libfaudes.a
COPY --from=faudes /usr/local/include/faudes/ /usr/local/include/
