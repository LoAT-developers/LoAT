FROM ubuntu:latest

RUN apt-get -y update
RUN apt-get install -y wget
RUN apt-get install unzip

RUN wget https://github.com/Z3Prover/z3/releases/download/z3-4.15.4/z3-4.15.4-x64-glibc-2.39.zip
RUN unzip z3-4.15.4-x64-glibc-2.39.zip
RUN mv z3-4.15.4-x64-glibc-2.39/bin/z3 /usr/bin/solver
