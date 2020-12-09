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

    char c = NULL_TERM;
    char last_c = NULL_TERM;
    int char_count = 0;
    for(int i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
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
        fclose(fp); 
    }
    
    fwrite(&char_count, sizeof(int), 1, stdout);
    printf("%c", last_c);
    return 0;
}
