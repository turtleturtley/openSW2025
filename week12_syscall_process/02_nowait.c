#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } 
    else if (pid == 0) {
        sleep(1);

        printf("Child process PID: %d\n", getpid());
        printf("Child process PPID: %d\n", getppid());
        
        exit(7);
    } 
    else {
        printf("Parent process PID: %d\n", getpid());
        printf("Parent process PPID: %d\n", getppid());
    }

    return 0;
}