// reader.c
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    const char *name = "/myshm";
    size_t size = 4096;

    int fd = shm_open(name, O_RDONLY, 0666);
    void *ptr = mmap(0, size, PROT_READ, MAP_SHARED, fd, 0);

    printf("[Reader] Read: %s\n", (char *)ptr);
    close(fd);
    return 0;
}