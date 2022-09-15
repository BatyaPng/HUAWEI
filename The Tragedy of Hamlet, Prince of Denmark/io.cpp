#include "io.hpp"

void input(FILE *fp) {
    fp = fopen("text.txt", "r");
    if (fp == NULL) {
        perror("fopen() failed");
        return;
    }

    fseek(fp, 0, SEEK_END);
    size_t fsize = (size_t) ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // printf("%d\n", fsize);  

    char *buffer = (char*) calloc(fsize + 1, sizeof(char));
    if (buffer == NULL) {
        perror("calloc() failed");
        return;
    }

    // printf("%d\n", fsize);  


    size_t result = fread(buffer, 1, fsize, fp);
    if (result != fsize) {
        perror("fred() failed");
        return;
    }

    fclose(fp);
    
    // puts(buffer);
    free(buffer);

    return;
}