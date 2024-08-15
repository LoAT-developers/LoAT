FROM mcr.microsoft.com/devcontainers/base:alpine-3.19

ENV CFLAGS -march=x86-64 -O2
xENV CXXFLAGS $CFLAGS

RUN apk add cmake boost-dev gdb
RUN apk add clang clang-dev
RUN apk add compiler-rt lld

COPY ./usr /usr
