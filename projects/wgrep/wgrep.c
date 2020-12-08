#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *argv[]){

    if(!(argc > 1)){
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }

    size_t BUFFER_SIZE = 10240;
    size_t *bs;
    bs = &BUFFER_SIZE;
    char buf[BUFFER_SIZE];
    char *b = buf;
    char *searchterm = argv[1];

    if(argc == 2){
        while(fgets(buf, BUFFER_SIZE, stdin) != NULL){
            if(strstr(buf, searchterm)){
                    printf("%s", buf);
            }
        }
    }
    else {
        for(int i = 2; i < argc; i++){
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("wgrep: cannot open file\n");
                exit(1);
            }

            while(getline(&b, bs, fp) != -1){
                if(strstr(buf, searchterm)){
                    printf("%s", buf);
                }
            }

            fclose(fp);   
        }
    }
    return 0;
}
