#ifndef _COMMON_FUNCTIONS_H_
#define _COMMON_FUNCTIONS_H_

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


void clean_buff();

int is_buff_empty();

int double_comp(const double a, const double b);

int mode(const int argc, const char *argv[]);

const double EPS = 1e-3;

const int MAX_LEN_OF_OUT_STR = 48;

enum NUM_ROOTS {
    ZERO,
    ONE_LIN,
    ONE_SQR,
    TWO_SQR,
    INF
};

enum MLE {
    MORE,
    LESS,
    EQUAL
};

enum TF {
    FALSE,
    TRUE
};

enum MODE {
    TEST_MODE,
    REGULAR_MODE
};

#endif
