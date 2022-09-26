#include "io.hpp"

struct text input(FILE *fp) {
    fp = fopen("./text/Hamlet.txt", "r");
    text text = {};

    size_t fsize = get_fsize(fp);
    if (fsize == 0) {
        perror("get_fsize() failed");
        return text;
    }

    char *buffer = (char*) calloc(fsize + 1, sizeof(char));
    if (buffer == NULL) {
        perror("calloc() failed");
        return text;
    }

    size_t result = fread(buffer, 1, fsize, fp);
    if (result != fsize) {
        perror("fred() failed");
        return text;
    }

    fclose(fp);

    text.buffer = buffer;
    text.len = fsize + 1; 
    text.n_lines = get_count_lines(text);

    return text;
}

void output(FILE *fp, line *lines_p, text text) {
    if (lines_p == NULL) {
        perror("lines_p null pointer");
        return;
    } else if (fp == NULL) {
        perror("fp null pointer");
        return;        
    }

    size_t n_lines = text.n_lines;
    char letter = 0;

    for (size_t i = 0; i < n_lines; i++) {
        for (size_t j = 0; j < lines_p[i].len; j++) {
            letter = lines_p[i].buffer[j];

            if (letter == 0) {
                fprintf(fp, "\n");
            } else
                fprintf(fp, "%c", letter);
        }
    }

    fprintf(fp, "\n");
}