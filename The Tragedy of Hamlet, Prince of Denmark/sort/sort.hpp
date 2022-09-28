#ifndef _SORT_H_
#define _SORT_H_

#include "../common_functions/common_functions.hpp"
#include "../io/io.hpp"

struct line {
    char *buffer = NULL;
    size_t len = 0;
};

struct text {
    char *buffer = NULL;
    size_t len = 0;
    size_t n_lines = 0;
};

struct line *get_lines(const text text);

void sort_and_write(const text text, FILE *fp);

int cmp_by_fc(const void *line_1, const void *line_2);

int cmp_by_lc(const void *line_1, const void *line_2);

void swap(void *arr[], size_t i, size_t j, size_t size_elem);

void my_qsort(void *ptr, size_t count, size_t size_one_elem, int (*comp)(const void *, const void *));

#endif