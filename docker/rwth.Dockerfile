FROM loat/loat-base:c53809ab

RUN git clone https://github.com/LoAT-developers/LoAT.git
WORKDIR /LoAT
RUN mkdir /LoAT/build
WORKDIR /LoAT/build
RUN cmake -DCMAKE_BUILD_TYPE=Release ..
RUN make -j
RUN mv loat-static /usr/bin/solver

