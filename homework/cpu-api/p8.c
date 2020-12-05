#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int pipefd[2];
    char buf;

    if(pipe(pipefd) == -1){
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        close(pipefd[1]);

        while (read(pipefd[0], &buf, 1) > 0){
            write(STDOUT_FILENO, &buf, 1);
        }

        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);
    } else {
        char *str = "Parent thread here!";
        close(pipefd[0]);
        write(pipefd[1], str, strlen(str));
        close(pipefd[1]);
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
    return 0;
}
