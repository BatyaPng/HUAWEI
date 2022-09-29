#ifndef _STACK_H_
#define _STACK_H_

#include "../CommonFunction/CommonFunction.hpp"
#include <math.h>

typedef double elem_t;

enum MAGIC_NUMBERS {
    FIRST_CAPACITY_STACK = 8
};

struct Stack {
    elem_t *data;
    size_t size;
    size_t capacity; 
};

int StackCtor(Stack *stk, elem_t value);

int StackPush(Stack *stk, elem_t value);

int StackPop(Stack *stk, elem_t *value);

static int StackResize(Stack *stk);

int StackDtor(Stack *stk);

int StackVerify(Stack *stk);

#endif