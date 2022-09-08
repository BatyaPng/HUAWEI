#ifndef _HELPER_FUNCTIONS_H_

#include <assert.h>
#include <math.h>
#include <stdio.h>

#define _HELPER_FUNCTIONS_H_

void clean_buff();

int is_buff_empty();

int double_comp (double a, double b);

const double EPS = 1e-3;

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
    TRUE = 0,
    FALSE = 1
};

#endif
