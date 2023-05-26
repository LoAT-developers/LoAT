FROM loat/base:latest
LABEL author="Florian Frohn"

RUN xbps-install -yS gmpxx-devel

RUN git clone https://github.com/SRI-CSL/libpoly.git
WORKDIR /libpoly/build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DCMAKE_C_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG" -DCMAKE_CXX_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG" ..
RUN make -j
RUN make install
