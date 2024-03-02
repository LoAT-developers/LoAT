FROM mcr.microsoft.com/devcontainers/base:alpine-3.19

RUN apk add cmake gmp-dev boost-dev

ENV LD_LIBRARY_PATH=/workspaces/LoAT-docker/lib
ENV CPATH=/workspaces/LoAT-docker/include:/workspaces/LoAT-docker/include/antlr4-runtime