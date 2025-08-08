FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update
RUN apt-get install -y \
    cmake \
    build-essential \
    openmpi-bin \
    libopenmpi-dev

WORKDIR /opt
COPY ./ovni /opt/ovni

WORKDIR /opt/ovni
RUN mkdir build && cd build && cmake .. && make -j16

RUN make -C build install && ldconfig

# RUN make -C build test