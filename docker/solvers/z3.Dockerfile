FROM ubuntu:latest

RUN apt-get -y update
RUN apt-get install -y wget

RUN wget https://github.com/Z3Prover/z3/releases/download/z3-4.13.3/z3-4.13.3-x64-glibc-2.35.zip
RUN unzip z3-4.13.3-x64-glibc-2.35.zip
RUN mv z3-4.13.3-x64-glibc-2.35/bin/z3 /usr/bin/solver
