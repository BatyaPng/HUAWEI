#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include "common_functions.hpp"

struct line {
    char *buffer = NULL;
    size_t len = 0;
};

void solve(line *line);

int line_cmp(const void *line_1, const void *line_2);

#endif