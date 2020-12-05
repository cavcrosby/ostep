#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        close(STDOUT_FILENO);
        printf("Child thread here!\n");
    } else {
        // parent goes down this path (original process)
        printf("Parent thread here!\n");
    }
    // more than likely what I expect to happen is since stdout will be closed from the terminal for the child process
    // printf will just dump the null-terminated string into a buffer and just leave it there (aka it goes nowhere and "Child thread here!\n" should not print to the terminal)
    // UPDATE: did exactly that
    return 0;
}
