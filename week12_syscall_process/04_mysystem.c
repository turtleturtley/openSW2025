#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int mysystem(const char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return -1;
    }
    else if (pid == 0) {
        execl("/bin/sh", "sh", "-c", command, NULL);
        exit(127);
    }
    else {
        waitpid(pid, &status, 0);
    }

    return status;
}

int main(void) {
    // system("ls -l | wc -l");
    // system("find . -name *.c");

    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good Bye~\n");

    return 0;
}