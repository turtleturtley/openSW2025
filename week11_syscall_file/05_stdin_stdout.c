#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 128

int main() {
    char buf[BUF_SIZE];
    int n;

    while(1) {
        n = read(0, buf, BUF_SIZE);
        
        if (n == 0) {
            printf("Detected EOF (Ctrl + D)\n");
            printf("Terminating read loop...\n");
            break;
        }

        write(1, buf, n);
    }

    return 0;
}