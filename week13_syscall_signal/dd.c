#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void) {
    sigset_t set, pending;

    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    sigprocmask(SIG_BLOCK, &set, NULL);

    printf("SIGINT blocked. Sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n\n");

    sleep(5);

    sigpending(&pending);

    if (sigismember(&pending, SIGINT)) {
        printf("SIGINT is pending\n");
    } else {
        printf("SIGINT is not pending\n");
    }

    return 0;
}