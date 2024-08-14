FROM mcr.microsoft.com/devcontainers/base:debian12

ENV CFLAGS -march=x86-64
ENV CXXFLAGS $CFLAGS
ENV LD_LIBRARY_PATH=/workspaces/LoAT-docker/docker/loat-base-image/usr/local/lib
ENV CPATH=/workspaces/LoAT-docker/docker/loat-base-image/usr/local/include

RUN apt-get update
RUN apt-get -y install cmake libboost-dev gdb
