#include "helper functions.hpp"

#ifndef _SOLVE_H_

#define _SOLVE_H_

NUM_ROOTS lin_solve(const double b, const double c, double *x_1);

NUM_ROOTS quadratic_solve(const double a, const double b, const double c, double *x_1, double *x_2);

NUM_ROOTS solve(const double a, const double b, const double c, double *x_1, double *x_2);

#endif

