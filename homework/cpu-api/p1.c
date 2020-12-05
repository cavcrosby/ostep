#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        x = 5;
        // value of x in the child process is now 5
        // value set by the child should be 'localized' to the child's address space (or its own memory)
        printf("Child's x: %d\n", x);
    } else {
        // parent goes down this path (original process)
        x = 200;
        wait(NULL);
        // value of x in the parent process is now 200
        // like the child, the parent's x should be 'localized' to the parents's address space (or its own memory)
        printf("Parent's x: %d\n", x);
    }
    return 0;
}
