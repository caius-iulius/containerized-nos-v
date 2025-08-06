// writer.c
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    const char *name = "/myshm";
    const char *msg = "Hello from writer! (external)";
    size_t size = 4096;

    int fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, size);

    void *ptr = mmap(0, size, PROT_WRITE, MAP_SHARED, fd, 0);
    sprintf(ptr, "%s", msg);

    printf("[Writer] Wrote: %s\n", msg);
    close(fd);
    return 0;
}