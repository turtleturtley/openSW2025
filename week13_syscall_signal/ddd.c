#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

struct two_double{
    double a;
    double b;
};

struct two_double data;

void sigint_handler(int _signo) {
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main(void){

    struct sigaction sa_sigalrm;
    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};
    
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGALRM);

    sa_sigalrm.sa_handler = sigint_handler;
    sigemptyset(&sa_sigalrm.sa_mask);
    sa_sigalrm.sa_flags = 0;
    if(sigaction(SIGALRM, &sa_sigalrm, NULL) == -1){
        perror("sigaction error: ");
        exit(0);
    }

    alarm(1);
    while(1){
        // block SIGALRM
        sigprocmask(SIG_BLOCK, &set, NULL);
        data = zeros;
        // unblock SIGALRM
        sigprocmask(SIG_UNBLOCK, &set, NULL);

        // block SIGALRM
        sigprocmask(SIG_BLOCK, &set, NULL);
        data = ones;
        // unblock SIGALRM
        sigprocmask(SIG_UNBLOCK, &set, NULL);
    }

    return 0;
}