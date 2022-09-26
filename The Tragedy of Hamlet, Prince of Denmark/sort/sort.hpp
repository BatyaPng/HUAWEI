#ifndef _SORT_H_
#define _SORT_H_

#include "../common_functions/common_functions.hpp"

struct line {
    char *buffer = NULL;
    size_t len = 0;
};

void sort_by_fw(line *line);

int line_cmp(const void *line_1, const void *line_2);

#endif