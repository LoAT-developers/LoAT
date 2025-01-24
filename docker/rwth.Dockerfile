FROM loat/loat-base:d31fb363

RUN git clone https://github.com/LoAT-developers/LoAT.git
WORKDIR /LoAT
RUN mkdir /LoAT/build
WORKDIR /LoAT/build
RUN cmake -DCMAKE_BUILD_TYPE=Release ..
RUN make -j
RUN mv loat-static /usr/bin/solver

