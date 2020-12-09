#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *argv[]){

    if(!(argc > 1)){
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }

    char buff[2048];
    for(int i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        while(fread(buff, sizeof(int), 4, fp) != 0 /* and fread(buff, sizeof(char), 4, fp) != 0?????? 4 bytes are int with 1 byte being a single ASCII char */){
            // for(int j = 0; buff[j] != '\0'; j++){
            //     printf("%c", buff[j]);
            // }
            printf("foo");
        };
        fclose(fp); 
    }  
    return 0;
}
