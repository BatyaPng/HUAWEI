#ifndef _COMMON_FUNCTION_H_
#define _COMMON_FUNCTION_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum ERROR_CODES {
    NP_PASSED = 1,
    CALLOC_FAILED,
    REALLOC_FAILED,
    NULL_SIZE_STACK,
    STACK_RESIZE_FAILED
};

#define ASSERTED(func, var, cntrlValue, retValue)   \
    if (strcmp(#func, "NP") == 0) {                 \
        if (var == cntrlValue) {                    \
            perror("null pointer passed");          \
                                                    \
            return retValue;                        \
        }                                           \
    } else if (var == cntrlValue) {                 \
        perror(#func"() failed");                   \
        return retValue;                            \
    }


size_t HashFAQ6(const void *data, size_t size);

#endif 