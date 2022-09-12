#ifndef _COMMON_FUNCTIONS_H_
#define _COMMON_FUNCTIONS_H_

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/** @brief Buffer clearing function */

void clean_buff();

/** @brief Checks if the buffer is empty */

int is_buff_not_empty();

/** 
 * @brief Compare two double numbers
 * 
 * @param [in] a, b Two double compared numbers
 * 
 * @return enum MLE MORE, LESS, OR EQUAL in relation to the number a to the number to b
 */

int double_comp(const double a, const double b);

/** 
 * @brief Determines the program mode by input parameters
 * 
 * @param [in] argc Number of arguments for the program
 * 
 * @param [in] argv An array of strings containing the input arguments for the program's mode
 * 
 * @return enum MODE TEST_MODE, REGULAR_MODE program operation mode 
 */

int mode(const int argc, const char *argv[]);

//Constant for comparing double number

const double EPS = 1e-3;

//Сonstant responsible for the len of the answer string

const int MAX_LEN_OF_OUT_STR = 48;

/** @brief Contains the number of roots of the equation */

enum NUM_ROOTS {
    ZERO = 0,
    ONE_LIN,
    ONE_SQR,
    TWO_SQR,
    INF
};

/** @brief Contains the enumeration for double_comp function */

enum MLE {
    MORE,
    LESS,
    EQUAL
};

/** @brief Contains the enumeration for true or false */

enum TF {
    FALSE,
    TRUE
};

/** @brief Contains the enumeration working mode */

enum MODE {
    TEST_MODE,
    REGULAR_MODE
};

#endif
