FROM loat/base:latest
LABEL author="Florian Frohn"

RUN git clone https://github.com/antlr/antlr4.git
WORKDIR /antlr4
RUN git checkout 4.11.1
RUN mkdir /antlr4/runtime/Cpp/build
WORKDIR /antlr4/runtime/Cpp/build
RUN cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_LIBDIR="/usr/local/lib" -DCMAKE_C_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG" -DCMAKE_CXX_FLAGS_RELEASE="-march=sandybridge -O3 -DNDEBUG"
RUN make -j
RUN make install
