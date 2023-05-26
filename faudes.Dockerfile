FROM loat/base:latest
LABEL author="Florian Frohn"

RUN xbps-install -yS readline-devel

RUN wget https://fgdes.tf.fau.de/archive/libfaudes-2_30b.tar.gz
RUN tar xf libfaudes-2_30b.tar.gz
WORKDIR /libfaudes-2_30b
RUN sed -i 's/MAINOPTS += -std=gnu++98 -D_GLIBCXX_USE_CXX11_ABI=0/MAINOPTS += -std=c++11/g' Makefile
RUN FAUDES_LINKING=static make -j
RUN cp /libfaudes-2_30b/libfaudes.a /usr/local/lib/
RUN cp -r /libfaudes-2_30b/include /usr/local/include/faudes
