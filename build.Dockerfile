# Triggers a build within a docker container. Assumes that the LoAT root
# directory is mounted at /LoAT.

FROM loat-docker:latest

RUN echo "repository=https://repo-default.voidlinux.org/current/musl" > /etc/xbps.d/00-repository-main.conf
RUN xbps-install -yS xbps
RUN xbps-install -ySu
RUN xbps-install -yS gcc git make cmake
RUN xbps-install -yS boost-devel cln-devel gmp-devel
RUN xbps-install -yS bash

RUN git config --global --add safe.directory /LoAT

CMD ["/LoAT/configure_and_build.sh"]
