FROM mcr.microsoft.com/devcontainers/base:alpine-3.19

ENV CFLAGS -march=x86-64
ENV CXXFLAGS $CFLAGS
ENV LD_LIBRARY_PATH=/workspaces/LoAT-docker/docker/loat-base-image/usr/local/lib
ENV CPATH=/workspaces/LoAT-docker/docker/loat-base-image/usr/local/include

RUN apk add cmake boost-dev gdb
RUN apk add clang clang-dev
RUN apk add compiler-rt lld
