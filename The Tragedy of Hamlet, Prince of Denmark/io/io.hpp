#ifndef _IO_H_
#define _IO_H_

#include "../common_functions/common_functions.hpp"
#include "../sort/sort.hpp"

struct text input(FILE *fp);

void output(FILE *fp, struct line *lines_p, text text);

#endif