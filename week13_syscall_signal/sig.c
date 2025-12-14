#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void sigint_handler(int signum) {
    printf("[SIGINT handler] ------------------\n");
    pid_t pid = fork();

    if (pid == 0) { // child
        char *argv[] = {"/usr/bin/ls", NULL};
        execve("/usr/bin/ls", argv, NULL);
        exit(0);
    }
    else { // parent
        wait(NULL);
    }
}

void sigquit_handler(int signum) {
    printf("[SIGQUIT handler] ------------------\n");
    pid_t pid = fork();

    if (pid == 0) { // child
        char *argv[] = {"/usr/bin/date", NULL};
        execve("/usr/bin/date", argv, NULL);
        exit(0);
    }
    else { // parent
        wait(NULL);
    }
}

void sigalrm_handler(int signum) {
    printf("[SIGALRM handler] ------------------\n");
    pid_t pid = fork();

    if (pid == 0) { // child
        char *argv[] = {"/usr/bin/whoami", NULL};
        execve("/usr/bin/whoami", argv, NULL);
        exit(0);
    }
    else { // parent
        wait(NULL);
        alarm(3);
    }
}


int main(void){

    // ... (화면의 이 부분에 해당하는 설정 코드입니다)
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
    signal(SIGALRM, sigalrm_handler);

    alarm(3);

    while(1){
        sleep(1);
    }

    return 0;
}