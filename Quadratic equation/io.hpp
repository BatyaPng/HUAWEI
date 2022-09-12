#ifndef _IO_H_
#define _IO_H_

#include <stdlib.h>
#include "common_functions.hpp"

/**
 * @brief Function providing input of values
 * 
 * @param [in] a, b, c Pointers to a variables, that contains equation coefficients
 * 
 */
 
void input(double *a, double *b, double *c);

/**
 * @brief Function providing output of values
 * 
 * @param [in] num_roots The number of roots to be shown in the answer
 * 
 * @param [in] x_1, x_2 Equation roots
 * 
 */

void output(const double x_1, const double x_2, const enum NUM_ROOTS num_roots);

#endif