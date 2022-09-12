/** @file */

#include "common_functions.hpp"

void clean_buff() {
    while (getchar() != '\n') {}
}

int is_buff_not_empty() {
    if (getchar() == '\n')
        return FALSE;
    return TRUE;
}

int double_comp(const double a, const double b) {
    if ((a - b) > EPS)
        return MORE;
    else if (fabs(a - b) < EPS)
        return EQUAL;
    else
        return LESS;
}

int mode(const int argc, const char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "-t") == 0)
        return TEST_MODE;
    return REGULAR_MODE;
}