# Starts QtCreator within a docker container. Assumes that the LoAT root
# directory is mounted at /LoAT.

FROM loat-docker:latest
LABEL author="Florian Frohn"

RUN xbps-install -yu xbps
RUN xbps-install -y qtcreator xauth mesa gdb clang-tools-extra

RUN git config --global --add safe.directory /LoAT

ARG TOKEN
RUN xauth add $TOKEN

CMD ["/usr/bin/qtcreator", "-settingspath", "/LoAT/", "-notour", "/LoAT/CMakeLists.txt"]
