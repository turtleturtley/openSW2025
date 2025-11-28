#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUF_SIZE 32

int main(int argc, char *argv[]) {
    int fd_src;
    int *fd_dests;
    int num_dests;
    int r_size;
    char buf[BUF_SIZE];
    int i;

    if (argc < 2) {
        printf("Usage: %s <source> [dest1] [dest2] ...\n", argv[0]);
        exit(1);
    }

    fd_src = open(argv[1], O_RDONLY);
    if (fd_src == -1) {
        perror("Source open failed");
        exit(1);
    }

    num_dests = argc - 2;
    if (num_dests > 0) {
        fd_dests = (int *)malloc(sizeof(int) * num_dests);
        for (i = 0; i < num_dests; i++) {
            fd_dests[i] = open(argv[i + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd_dests[i] == -1) {
                perror("Dest open failed");
                exit(1);
            }
        }
    }

    while ((r_size = read(fd_src, buf, BUF_SIZE)) > 0) {
        write(1, buf, r_size);
        
        for (i = 0; i < num_dests; i++) {
            write(fd_dests[i], buf, r_size);
        }
    }

    close(fd_src);
    for (i = 0; i < num_dests; i++) {
        close(fd_dests[i]);
    }
    
    if (num_dests > 0) {
        free(fd_dests);
    }

    return 0;
}