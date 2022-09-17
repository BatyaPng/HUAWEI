#include "io.hpp"

struct line *input(FILE *fp) {
    fp = fopen("text.txt", "r");
    
    size_t fsize = get_fsize(fp);
    if (fsize == 0) {
        perror("get_fsize() failed");
        return NULL;
    }

    char *buffer = (char*) calloc(fsize + 1, sizeof(char));
    if (buffer == NULL) {
        perror("calloc() failed");
        return NULL;
    }

    size_t result = fread(buffer, 1, fsize, fp);
    if (result != fsize) {
        perror("fred() failed");
        return NULL;
    }

    fclose(fp);

    struct line *text = (struct line *) calloc(1, sizeof(struct line));
    text -> buffer = buffer;
    text -> len = fsize + 1; 

    // puts(string -> buffer);
    // printf("%d\n", &string);
    // printf("%d\n", string -> len);

    return text;
}