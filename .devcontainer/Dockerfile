FROM mcr.microsoft.com/devcontainers/base:alpine-3.19

ENV CFLAGS -march=x86-64
ENV CXXFLAGS $CFLAGS
ENV LD_LIBRARY_PATH=/workspaces/LoAT-docker/docker/loat-base-image/usr/local/lib
ENV CPATH=/workspaces/LoAT-docker/docker/loat-base-image/usr/local/include

RUN apk add cmake gmp-dev libgmpxx boost-dev gdb mpfr-dev
