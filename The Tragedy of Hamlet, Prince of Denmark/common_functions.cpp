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