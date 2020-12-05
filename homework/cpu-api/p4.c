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
        // char *childargs[2];
        // childargs[0] = strdup("/usr/bin/ls");
        // childargs[1] = NULL;
        char *executable = "/usr/bin/ls";
        execl(executable, ".");  
    } else {
        wait(NULL);
    }
    // A lot of variants of the exec system call exists to serve really as small combinations of wrapper options
    // l vs v really just specifies using the pointers to null terminated strings passed into the system call vs an array of pointers to null terminated strings
    // e specifies an optional environ for the calling process
    // p is appended if the system call is to the look on the path for arg[0]
    return 0;
}
