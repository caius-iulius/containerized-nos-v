# RUN apt-get update && apt-get clean && rm -rf /var/lib/apt/lists/*
FROM ubuntu:latest AS base

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    cmake \
    build-essential \
    openmpi-bin \
    libopenmpi-dev \
    automake \
    autoconf \
    libtool \
    pkg-config \
    numactl \
    libnuma-dev \
    libboost-dev

FROM base AS ovni

WORKDIR /opt
COPY ./ovni /opt/ovni
WORKDIR /opt/ovni

RUN mkdir build && cd build && cmake .. && make -j16

RUN make -C build install && ldconfig

# RUN make -C build test

FROM ovni AS nosv

WORKDIR /opt
COPY ./nos-v /opt/nos-v
WORKDIR /opt/nos-v

RUN autoreconf -f -i -v
RUN ./configure \
    --with-ovni=/ \
    && make -j16 all

# shared memory isn't preserved across containers, so we need to create it right before running the tests
# RUN mkdir /dev/shm/nosv && make check
RUN make install && ldconfig

FROM nosv AS nodes

WORKDIR /opt
COPY ./nodes /opt/nodes
WORKDIR /opt/nodes

RUN autoreconf -f -i -v
RUN ./configure \
    --with-ovni=/ \
    --with-nosv=/ \
    && make -j16 all

RUN make install && ldconfig