#ifndef _STACK_H_
#define _STACK_H_

#define DEBUG

#include "CommonFunction.hpp"
#include <math.h>

enum ERROR_CODES {
    NP_PASSED = 1
};

typedef double elem_t;

enum MAGIC_NUMBERS {
    FIRST_CAPACITY_STACK = 3
};

enum MODE_STACK_RESIZE {
    UP,
    DOWN
};

#ifdef DEBUG
    struct VarInfo {
        char *fileName;
        char *funcName;
        size_t lineNumber;
        char *varName;
    };
#endif

struct Stack {
    elem_t *data;
    size_t size;
    size_t capacity;

    #ifdef DEBUG
        struct VarInfo VarInfo = {};
    #endif 
};

#ifdef DEBUG
    #define VAR_INFO_PARAM , const char *fileName, const char *funcName, const size_t lineNumber, const char *varName
    #define VAR_INFO(varName) , __FILE__, __func__, __LINE__, #varName 
#else  
    #define VAR_INFO_PARAM
    #define VAR_INFO(...)
#endif

#define StackDump(varName, streamOut) StackDumpFunc(varName, streamOut VAR_INFO(varName))
#define StackCtor(stkP, value) StackCtorFunc(stkP, value VAR_INFO(stkP))

int StackCtorFunc(Stack *stk, elem_t value VAR_INFO_PARAM);

int StackPush(Stack *stk, elem_t value);

int StackPop(Stack *stk, elem_t *value);

int StackDtor(Stack *stk);

int StackVerify(const Stack stk);

int StackDumpFunc(const Stack stk , FILE* streamOut VAR_INFO_PARAM);

#endif