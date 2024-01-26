# Triggers a build within a docker container. Assumes that the LoAT root
# directory is mounted at /LoAT.

FROM voidlinux/voidlinux-musl:latest as base

RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -yS xbps
RUN xbps-install -yS gcc git make cmake
RUN xbps-install -yS boost-devel cln-devel gmp-devel
RUN xbps-install -yS bash

RUN git config --global --add safe.directory /LoAT

FROM base as build

ENV LD_LIBRARY_PATH=/LoAT/lib
ENV CPATH=/LoAT/include:/LoAT/include/antlr4-runtime

CMD ["/LoAT/scripts/configure_and_build.sh"]
