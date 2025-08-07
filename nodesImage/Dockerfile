FROM nosv:latest
ENV DEBIAN_FRONTEND=noninteractive
# RUN apt-get install -y \
#     git \
#     automake \
#     autoconf \
#     libtool \
#     pkg-config \
#     build-essential \
#     libboost-all-dev

WORKDIR /opt

COPY ./nodes /opt/nodes
WORKDIR /opt/nodes

RUN autoreconf -f -i -v
RUN ./configure \
    --with-nosv=/ \
    && make all

RUN make install && ldconfig

# RUN make clean && apt-get clean && rm -rf /var/lib/apt/lists/*
CMD ["/bin/bash"]