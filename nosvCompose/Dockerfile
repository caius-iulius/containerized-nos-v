FROM nosv:latest

WORKDIR /app

COPY basic_init.c ./

RUN gcc -o basic_init basic_init.c -lnosv

CMD ["bash"]