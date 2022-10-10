#ifndef _STACK_H_
#define _STACK_H_

// #define StackDump()

#include "CommonFunction.hpp"
#include <math.h>

typedef double elem_t;

enum MAGIC_NUMBERS {
    FIRST_CAPACITY_STACK = 3
};

enum MODE_STACK_RESIZE {
    UP,
    DOWN
};

struct Stack {
    elem_t *data;
    size_t size;
    size_t capacity; 
};

int StackCtor(Stack *stk, elem_t value);

int StackPush(Stack *stk, elem_t value);

int StackPop(Stack *stk, elem_t *value);

int StackDtor(Stack *stk);

int StackVerify(const Stack stk);

// int StackDumpFunc(const Stack stk, );

#endif