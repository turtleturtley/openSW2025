#include <sys/types.h> //
#include <unistd.h>

#include <stdio.h> //printf()를 써야해서

int main() {

    pid_t my_pid;

    my_pid  = getpid();

    printf("my pid is %lu\n", (unsigned long)my_pid);
    
    return 0;
}