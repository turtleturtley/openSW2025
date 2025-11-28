#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    for (i = 1; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);

        if (fd == -1) {
            perror("Open failed");
        } else {
            printf("File opened: %s, fd: %d\n", argv[i], fd);
            close(fd);
        }
    }

    return 0;
}