#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        int parentpid = (int) getpid()-1;
        kill(parentpid, SIGTSTP);
        printf("hello\n");
        kill(parentpid, SIGCONT);
    } else {
        signal(SIGTSTP, SIG_DFL);
        signal(SIGCONT, SIG_DFL);
        printf("goodbye\n");
    }
    // by sending the signal SIGTSTP to the parent process (assuming parents pid will always be the (child pid) - 1)
    // we can stop the parent process, print hello, and then send the signal SIGCONT to the parent to have the process
    // resume

    // SIG_DFL basically says that the process should act on the process as it would by default, of course, this
    // can be overridden

    // in other words, yes, you don't have to use the system call wait(), though this requires more work
    return 0;
}
