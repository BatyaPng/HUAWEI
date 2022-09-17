#include "common_functions.hpp"

size_t get_fsize(FILE *fp) {
    if (fp == NULL) {
        perror("null pointer passed");
        return 0;
    }

    fseek(fp, 0, SEEK_END);

    size_t fsize = (size_t) ftell(fp);
    if (fsize == (size_t) -1L) {
        perror("ftell() failed");
        return 0;
    }

    fseek(fp, 0, SEEK_SET);

    return fsize;
}

size_t get_count_lines(line text) {
    size_t c_str = 1;

    for(size_t i = 0; i < text.len; i++) {
        char ch = text.buffer[i]; 

        if (ch == '\n') {
            c_str++;
        }
    }

    return c_str;
}

int min(const int a, const int b) { return (a < b) ? a : b; }