FROM ubuntu:latest

RUN apt-get -y update
RUN apt-get install -y wget

RUN wget https://github.com/usi-verification-and-security/golem/releases/download/v0.6.2/golem-x64-linux.tar.bz2

RUN apt-get install -y lbzip2

RUN tar xf golem-x64-linux.tar.bz2
RUN mv golem /usr/bin/solver
