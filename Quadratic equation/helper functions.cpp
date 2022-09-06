#include "helper functions.hpp"

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