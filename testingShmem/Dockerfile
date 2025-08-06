FROM gcc:13-bookworm

WORKDIR /app

COPY writer.c reader.c ./

RUN gcc -o writer writer.c -lrt && \
    gcc -o reader reader.c -lrt

CMD ["bash"]