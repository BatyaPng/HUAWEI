#include <math.h>
#include <stdio.h>

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

void clean_buff() {
    while (getchar() != '\n') {}
}

int is_buff_empty() {
    if (getchar() != '\n')
        return FALSE;
    return TRUE;
}

int double_comp (double a, double b) {
    if (a > b)
        return MORE;
    else if (fabs(a - b) < EPS)
        return EQUAL;
    else
        return LESS;
}