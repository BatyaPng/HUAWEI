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

void swap(void *arr[], size_t i, size_t j, size_t size_elem) {
    if (arr == NULL) {
        perror("null poiner arr[] passed");
        return;
    }

    void *tmp = calloc(1, size_elem);
    memcpy(tmp ,((*(char **) arr) + i * size_elem), size_elem);

    memcpy(((*(char **) arr) + i * size_elem), ((*(char **) arr) + j * size_elem), size_elem);
    memcpy(((*(char **) arr) + j * size_elem), tmp, size_elem);

    free(tmp);
}

void my_qsort(void *arr, size_t count, size_t size_elem, int (*comp)(const void *, const void *)) {
    if (arr == NULL) {
        perror("null pointer arr passed");
        return;
    }

    if (size_elem == sizeof(char)) {
        char last_elem = ((char *) arr)[count - 1];

        while (last_elem == 0) {
            count--;
            last_elem = ((char *) arr)[count - 1];
        }
    }

    if (count == 1) {
        return;
    }

    size_t left = 0;
    size_t middle = count / 2;
    size_t right = count - 1;

    void *left_elem = NULL;
    void *middle_elem = NULL;
    void *right_elem = NULL;

    do {
        left_elem = (void *) ((char*) arr + (size_elem * left));
        middle_elem = (void *) ((char*) arr + (size_elem * middle));
        right_elem = (void *) ((char*) arr + (size_elem * right));

        while ((*comp)(left_elem, middle_elem) < 0) {
            left++;
            left_elem = (void *) ((char*) arr + (size_elem * left));
        }

        while ((*comp)(right_elem, middle_elem) > 0) {
            right--;
            right_elem = (void *) ((char*) arr + (size_elem * right));
        }

        if (left <= right) {
            swap(&arr, left, right, size_elem);

            left++;
            right--;
        }

    } while (left <= right);

    if (right > 0)
        my_qsort(arr, right + 1, size_elem, comp);
    if (left < count) {
        void *r_arr = (void *) ((char *) arr + size_elem * left); 
        my_qsort(r_arr, count - left, size_elem, comp);
    }
}