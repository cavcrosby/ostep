#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *argv[]){

    if(!(argc > 1)){
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }

    int buff[1];
    for(int i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        while(1){
            size_t return_code = fread(buff, sizeof(int), 1, fp);
            if(return_code == 0){
                break;
            }
            int times_to_print = buff[0];
            fread(buff, sizeof(char), 1, fp);
            for(int j = 0; j < times_to_print; j++){
                printf("%c", buff[0]);
            }
        }
        fclose(fp); 
    }  
    return 0;
}
