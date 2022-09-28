#ifndef _COMMON_FUNCTIONS_H_
#define _COMMON_FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../sort/sort.hpp"

size_t get_fsize(FILE *fp);

size_t get_count_lines(const struct text text);

int min(const int a, const int b);

void destructor(char *buffer, struct line *lines_p);

void swap(void *arr[], size_t i, size_t j);

void my_qsort(void *arr[], size_t count, size_t size, int (*comp)(const void *, const void *));

#endif