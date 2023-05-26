FROM loat/base:latest
LABEL author="Florian Frohn"

RUN xbps-install -yS libtool gmpxx-devel cln-devel giac-devel

COPY --from=loat/ginac /usr/local/lib64/libginac.a /usr/local/lib64/libginac.a
COPY --from=loat/ginac /usr/local/include/ginac /usr/local/include/ginac

COPY --from=loat/ntl /usr/local/include/NTL /usr/local/include/NTL
COPY --from=loat/ntl /usr/local/lib/libntl.a /usr/local/lib/libntl.a

RUN git clone https://github.com/aprove-developers/LoAT-purrs.git
WORKDIR /LoAT-purrs
RUN autoreconf --install
RUN automake
RUN ./configure --with-cxxflags='-march=sandybridge -O3 -DNDEBUG'
RUN make -j
RUN make install
