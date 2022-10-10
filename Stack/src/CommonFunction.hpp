#ifndef _COMMON_FUNCTION_H_
#define _COMMON_FUNCTION_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// enum ASSERTED_MODE {}

#define ASSERTED(func, var, cntrlValue, retValue) \
    if (strcmp(#func, "NP") == 0) {               \
        if (var == cntrlValue) {                  \
        perror("null pointer passed");            \
                                                  \
        return retValue;                          \
        }                                         \
    } else if (var == cntrlValue) {               \
        perror(#func"() failed");                 \
        return retValue;                          \
    }

#endif 