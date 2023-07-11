FROM loat/loat:latest
LABEL author="Florian Frohn"

ARG TOKEN

RUN xbps-install -yS qtcreator xauth mesa gdb

RUN xauth add $TOKEN

CMD ["/usr/bin/qtcreator", "-settingspath", "/LoAT/", "-notour", "/LoAT/CMakeLists.txt"]
