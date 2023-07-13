FROM loat-docker:latest
LABEL author="Florian Frohn"

RUN xbps-install -yS qtcreator xauth mesa gdb clang clang-tools-extra

ARG TOKEN

RUN xauth add $TOKEN

CMD ["/usr/bin/qtcreator", "-settingspath", "/LoAT/", "-notour", "/LoAT/CMakeLists.txt"]
