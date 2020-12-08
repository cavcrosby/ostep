#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
    struct timeval start, end;
    char buf[200];
    double elapsed_time;
    
    gettimeofday(&start, NULL);
 
    read(STDIN_FILENO, buf, 0);
 
    gettimeofday(&end, NULL);

    // for reference https://stackoverflow.com/questions/2150291/how-do-i-measure-a-time-interval-in-c
    // compute and print the elapsed time in millisec
    elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0;      // sec (base) to ms (milli)
    elapsed_time += (end.tv_usec - start.tv_usec) / 1000.0;   // us (micro) to ms (milli)
    elapsed_time *= 1e3;
    printf("%.2f ms\n", elapsed_time);

    return 0;
}
