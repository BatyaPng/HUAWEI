#ifndef _STACK_H_
#define _STACK_H_

#include "../CommonFunction/CommonFunction.hpp"
#include <math.h>

typedef double elem_t;

enum MAGIC_NUMBERS {
    FIRST_CAPACITY_STACK = 8
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

static int StackResize(Stack *stk, MODE_STACK_RESIZE);

int StackDtor(Stack *stk);

int StackVerify(Stack *stk);

#endif