#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()  {
    
    pid_t pid;

    pid = getpid();

    printf("pid : %d\n", pid);
    printf("ppid: %d\n", getppid());

    return 0;
}