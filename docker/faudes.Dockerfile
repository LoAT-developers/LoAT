FROM voidlinux/voidlinux-musl:latest as base

ENV CFLAGS -march=x86-64 -O2
ENV CXXFLAGS $CFLAGS
RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -ySu xbps
RUN xbps-install -ySu
RUN xbps-install -yS bash gcc make readline-devel wget


FROM base as faudes

RUN xbps-install -yS 

RUN wget https://fgdes.tf.fau.de/archive/libfaudes-2_30b.tar.gz
RUN tar xf libfaudes-2_30b.tar.gz
WORKDIR /libfaudes-2_30b
RUN sed -i 's/MAINOPTS += -std=gnu++98 -D_GLIBCXX_USE_CXX11_ABI=0/MAINOPTS += -std=c++11/g' Makefile
RUN FAUDES_LINKING=static make -j
RUN cp /libfaudes-2_30b/libfaudes.a /usr/local/lib/
RUN cp -r /libfaudes-2_30b/include /usr/local/include/faudes
