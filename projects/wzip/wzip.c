#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define NULL_TERM '\0'

int main (int argc, char *argv[]){

    if(!(argc > 1)){
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }

    for(int i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        char c = NULL_TERM;
        char last_c = NULL_TERM;
        int char_count = 0;
        while((c = fgetc(fp)) != EOF){
            if(last_c == NULL_TERM){
                last_c = c;
                char_count = 1;
            }
            else if (last_c == c){
                ++char_count;
            }
            else {
                fwrite(&char_count, sizeof(int), 1, stdout);
                printf("%c", last_c);
                last_c = c;
                char_count = 1;
            }
        }
        fwrite(&char_count, sizeof(int), 1, stdout);
        printf("%c", last_c);
        fclose(fp);   
    }

    // size_t BUFFER_SIZE = 10240;
    // size_t *bs;
    // bs = &BUFFER_SIZE;
    // char buf[BUFFER_SIZE];
    // char *b = buf;
    // char *searchterm = argv[1];

    // if(argc == 2){
    //     while(fgets(buf, BUFFER_SIZE, stdin) != NULL){
    //         if(strstr(buf, searchterm)){
    //                 printf("%s", buf);
    //         }
    //     }
    // }
    // else {
    //     for(int i = 2; i < argc; i++){
    //         FILE *fp = fopen(argv[i], "r");
    //         if (fp == NULL) {
    //             printf("wgrep: cannot open file\n");
    //             exit(1);
    //         }

    //         while(getline(&b, bs, fp) != -1){
    //             if(strstr(buf, searchterm)){
    //                 printf("%s", buf);
    //             }
    //         }

    //         fclose(fp);   
    //     }
    // }
    return 0;
}
