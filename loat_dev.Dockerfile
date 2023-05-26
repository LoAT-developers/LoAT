FROM loat/loat:latest
LABEL author="Florian Frohn"

RUN xbps-install -yS qtcreator xauth mesa

RUN xauth add batman/unix:0  MIT-MAGIC-COOKIE-1  02d213424c3031a39ac84c2b5d19a978

CMD ["/usr/bin/qtcreator"]
