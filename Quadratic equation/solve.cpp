#include "solve.hpp"

NUM_ROOTS lin_solve(const double b, const double c, double *x_1) {
    if (double_comp(b, 0) != EQUAL) {
        *x_1 = - c / b;
        return ONE_LIN;
    } else if (double_comp(b, 0) == EQUAL && double_comp(c, 0) == EQUAL)
        return INF;
    return ZERO;
}

NUM_ROOTS quadratic_solve(const double a, const double b, const double c, double *x_1, double *x_2) {
    double D = b * b - 4 * a * c;

    if (double_comp(D, 0) == LESS)
        return ZERO;

    double sqrt_D = sqrt(D);
    if (double_comp(D, 0) == MORE) {
        *x_1 = (-b + sqrt_D) / (2 * a);
        *x_2 = (-b - sqrt_D) / (2 * a);
        return TWO_SQR;
    } else if (double_comp(D, 0) == EQUAL) {
        *x_1 = -b / (2 * a);
        return ONE_SQR;
    }

    printf("Runtime error\n");
    abort();
}


NUM_ROOTS solve(const double a, const double b, const double c, double *x_1, double *x_2) {
    assert(isnan(a) + isnan(b) + isnan(c) == 0);
    assert(x_1 || x_2);

    if (double_comp(a, 0) == EQUAL) {
        return lin_solve(b, c, x_1);
    }
    return quadratic_solve(a, b, c, x_1, x_2);
}