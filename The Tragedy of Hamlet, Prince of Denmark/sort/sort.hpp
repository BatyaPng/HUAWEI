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

int cmp_by_fc(const void *line_1, const void *line_2);

int cmp_by_lc(const void *line_1, const void *line_2);

#endif