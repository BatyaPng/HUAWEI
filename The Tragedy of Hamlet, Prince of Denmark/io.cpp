#include "io.hpp"

void input(FILE *fp) {
    fp = fopen("text.txt", "r");
    
    size_t fsize = get_fsize(fp);
    if (fsize == 0) {
        perror("get_fsize() failed");
        return;
    }

    char *buffer = (char*) calloc(fsize + 1, sizeof(char));
    if (buffer == NULL) {
        perror("calloc() failed");
        return;
    }

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