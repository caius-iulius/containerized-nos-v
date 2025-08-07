FROM ubuntu:latest
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && \
    apt-get install -y \
    automake \
    autoconf \
    libtool \
    pkg-config \
    build-essential \
    numactl \
    libnuma-dev \
    build-essential # only needed by NODES, see its dockerfile for details

WORKDIR /opt

COPY ./nos-v /opt/nos-v
WORKDIR /opt/nos-v

RUN autoreconf -f -i -v
RUN ./configure && make all

# shared memory isn't preserved across containers, so we need to create it right before running the tests
# RUN mkdir /dev/shm/nosv && make check
RUN make install && ldconfig

# RUN make clean && apt-get clean && rm -rf /var/lib/apt/lists/*
CMD ["/bin/bash"]