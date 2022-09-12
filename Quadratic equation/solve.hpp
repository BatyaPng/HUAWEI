#ifndef _SOLVE_H_
#define _SOLVE_H_

#include "common_functions.hpp"

/**
 * @brief Solution for linear equation
 *
 * @param [in] b, c Linear equation coefficients
 *
 * @param [out] x_1 Pointer to a variable, that contains root of equation
 *
 * @return enum NUM_ROOTS, that contains number of roots
 * 
 */
 
NUM_ROOTS lin_solve(const double b, const double c, double *x_1);

/**
 * @brief Solution for quadratic equation
 * 
 * @param [in] a, b, c Quadraric equation coefficients
 * 
 * @param [out] x_1, x_2 Pointers to a variables, that contain roots of equation
 * 
 * @return enum NUM_ROOTS, that contains number of roots
 * 
 */

NUM_ROOTS quadratic_solve(const double a, const double b, const double c, double *x_1, double *x_2);

/**
 * @brief Determines what type of equation given coefficients
 * 
 * @param [in] a, b, c Equation coefficients
 * 
 * @param [out] x_1, x_2 Pointers to a variables, that contain roots of equation
 * 
 * @return enum NUM_ROOTS, that contains number of roots
 * 
 */

NUM_ROOTS solve(const double a, const double b, const double c, double *x_1, double *x_2);

#endif

