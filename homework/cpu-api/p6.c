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
    int parentspid = (int) getpid();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        int rv = waitpid(parentspid+1, NULL, 0);
        printf("child's pid: %d\n", (int) getpid());
        printf("%d\n", rv);
        char *executable = "/usr/bin/ls";
        execl(executable, ".");  
    } else {
        // int rv = waitpid((int) getpid()+1, NULL, 0);
        printf("parent's pid: %d\n", (int) getpid());
        // printf("%d\n", rv);
    }
    // it appears waitpid could potentially be useful by allowing the child to wait on a particular process
    // or if particular option wanted to be use (give the third argument in waitpid() but in my example I just set it to 0)
    return 0;
}
