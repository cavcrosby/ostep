#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE (512)

int main (int argc, char *argv[]){

    char buf[BUFFER_SIZE];

    if(!(argc > 1)){
        return 0;
    }

    for(int i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        while(fgets(buf, BUFFER_SIZE, fp) != NULL){
            printf("%s", buf);
        }

        fclose(fp);   
    }

    return 0;
}
