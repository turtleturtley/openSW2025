#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

    if (argc != 2) {
        printf("Usage : opentest filename\n");
        return 1;
    }

    int fd = open (argv[1], O_RDONLY);
    
    if(fd == -1) {
        // printf("'%s' : File open error\n", (char *)argv[1]);
        perror(argv[1]);
    }

    else {
        printf("'%s' : File open successful!\n", (char *)argv[1]);
    }

    // printf("argc: %d\n", argc);

    // for (int i = 0; i < argc; i++) {
    //     printf("argv[%d]: %s\n", i, argv[i]);
    // }

    return 0;
}