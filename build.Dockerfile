# Triggers a build within a docker container. Assumes that the LoAT root
# directory is mounted at /LoAT.

FROM loat-docker:latest
LABEL author="Florian Frohn"

RUN git config --global --add safe.directory /LoAT

WORKDIR /LoAT/

CMD ["./configure_and_build.sh"]

