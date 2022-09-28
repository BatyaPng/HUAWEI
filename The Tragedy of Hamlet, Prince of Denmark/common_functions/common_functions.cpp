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

size_t get_count_lines(const text text) {
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

void destructor(char *buffer, line *lines_p) {
    if (buffer == NULL) {
        perror("buffer null pointer");
        return;
    } else if (lines_p == NULL) {
        perror("lines_p null pointer");
        return;
    }

    free(buffer);
    free(lines_p);
}

void swap(void *arr[], size_t i, size_t j, size_t size) {
    if (arr == NULL) {
        perror("null poiner arr[] passed");
        return;
    }

    void *tmp = calloc(1, size);
    memcpy(tmp ,((*(char **) arr) + i * size), size);

    memcpy(((*(char **) arr) + i * size), ((*(char **) arr) + j * size), size);
    memcpy(((*(char **) arr) + j * size), tmp, size);

    free(tmp);
}

void my_qsort(void *arr, size_t count, size_t size, int (*comp)(const void *, const void *)) {
    if (arr == NULL) {
        perror("null pointer arr passed");
        return;
    }

    if (count == 1) {
        return;
    }

    size_t middle = count / 2;
    size_t left = 0;
    size_t right = count - 1;

    void *middle_elem = NULL;
    void *left_elem = NULL;
    void *right_elem = NULL;

    do {
        middle_elem = (void *) ((char*) arr + (size * middle));
        left_elem = (void *) ((char*) arr + (size * left));
        right_elem = (void *) ((char*) arr + (size * right));

        while ((*comp)(left_elem, middle_elem) < 0) {
            left++;
        }

        while ((*comp)(right_elem, middle_elem) > 0) {
            right--;
        }

        swap(arr, left, right, size);
        left++;
        right--;

    } while (left <= right);

    my_qsort(arr, middle, size, comp);

    void *r_arr = (void *) ((char *) arr + size * middle); 
    my_qsort(r_arr, count - middle, size, comp);
}