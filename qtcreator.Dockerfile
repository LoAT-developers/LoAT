FROM loat/loat:latest
LABEL author="Florian Frohn"

ARG TOKEN

RUN xbps-install -yS qtcreator xauth mesa

RUN xauth add $TOKEN

CMD ["/usr/bin/qtcreator"]
