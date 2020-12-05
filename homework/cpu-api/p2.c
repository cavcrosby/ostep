#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    close(STDOUT_FILENO); 
	open("./p2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child thread here!\n");
    } else {
        // parent goes down this path (original process)
        printf("Parent thread here!\n");
    }
    // both the child and parent can access the newly opened file descriptor
    // depending on order of instruction execution, either the parent or child will 'write' first to the file/descriptor
    return 0;
}
