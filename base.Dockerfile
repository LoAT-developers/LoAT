FROM voidlinux/voidlinux-musl:latest
LABEL author="Florian Frohn"

RUN xbps-install -yS xbps
RUN xbps-install -ySu
RUN xbps-install -yS gcc git automake autoconf make cmake wget python-devel bash
