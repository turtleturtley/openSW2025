#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid = getpid(); 

    while(1) {
        printf("Running... PID: %d\n", pid); 
        sleep(1);
    }
    return 0;
}