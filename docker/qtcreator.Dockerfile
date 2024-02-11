# Starts QtCreator within a docker container. Assumes that the LoAT root
# directory is mounted at /LoAT.

FROM voidlinux/voidlinux-musl:latest as base

RUN echo noextract=/etc/hosts > /etc/xbps.d/test.conf
RUN echo "repository=https://repo-de.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -ySu xbps
RUN xbps-install -ySu
RUN xbps-install -yS gcc git make cmake bash
RUN xbps-install -yS boost-devel cln-devel gmp-devel
RUN xbps-install -yS qtcreator xauth mesa gdb clang-tools-extra

RUN git config --global --add safe.directory /LoAT

FROM base as build

ARG TOKEN
RUN xauth add $TOKEN

ENV LD_LIBRARY_PATH=/LoAT/lib
ENV CPATH=/LoAT/include:/LoAT/include/antlr4-runtime

CMD ["/usr/bin/qtcreator", "-settingspath", "/LoAT/", "-notour", "/LoAT/CMakeLists.txt"]
