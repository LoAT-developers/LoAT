ARG PLATFORM=linux/arm64
FROM ubuntu:latest

RUN apt-get -y update
RUN apt-get install -y wget

RUN wget https://github.com/uuverifiers/eldarica/releases/download/v2.1/eldarica-bin-2.1.zip

RUN apt-get install -y unzip

RUN unzip eldarica-bin-2.1.zip

RUN apt-get install -y default-jre