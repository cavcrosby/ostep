#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        int rv = wait(NULL);
        printf("child's pid: %d\n", (int) getpid());
        printf("%d\n", rv);
        char *executable = "/usr/bin/ls";
        execl(executable, ".");  
    } else {
        // int rv = wait(NULL);
        printf("parent's pid: %d\n", (int) getpid());
        // printf("%d\n", rv);
    }
    // it appears the return value is the child's process id
    // however, that said, calling wait in the child process returns -1, which according to the man page makes sense: 'meaning wait for any child process'
    return 0;
}
