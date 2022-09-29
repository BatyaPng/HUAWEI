#ifndef _IO_H_
#define _IO_H_

#include "../common_functions/common_functions.hpp"
#include "../sort/sort.hpp"

enum MODE {
    BEFORE_SORTING,
    AFTER_SORTING    
};

struct text input(FILE *fp);

void output(FILE *fp, struct line *lines_p, text text, MODE);

#endif