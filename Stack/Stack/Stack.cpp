#include "stack.hpp"

#define POISON NAN

int StackCtor(Stack *stk, elem_t value) {
    ASSERTED(NP, stk, NULL, 1);

    stk->data = (elem_t *) calloc(FIRST_CAPACITY_STACK, sizeof(elem_t));
    ASSERTED(calloc, stk->data, NULL, 2);

    for (int i = 0; i < FIRST_CAPACITY_STACK; i++) {
        stk->data[i] = POISON;
    }

    stk->capacity = FIRST_CAPACITY_STACK;
    stk->data[0] = value;

    return 0;
}

int StackDtor(Stack *stk) {
    // StackVerify;

    for (size_t i = 0; i < stk->capacity; i++) {
        stk->data[i] = POISON;
    }

    free(stk->data);

    return 0;
}

static int StackResize(Stack *stk, MODE_STACK_RESIZE) {
    // StackVerify;

    void *tmpBuf = NULL;
    
    if (MODE_STACK_RESIZE == UP) {
        tmpBuf = realloc(stk->data, 2 * (stk->capacity));
        ASSERTED(realloc, tmpBuf, NULL, 1);

        stk->data = (elem_t *) tmpBuf;
        stk->capacity *= 2;
    } else {
        tmpBuf = realloc(stk->data, (stk->capacity) / 2);
        ASSERTED(realloc, tmpBuf, NULL, 1);

        stk->data = (elem_t *) tmpBuf;
        stk->capacity /= 2;
    }



    for (size_t i = stk->size; i < stk->capacity; i++) {
        stk->data[i] = POISON;
    }

    return 0;     
}

int StackPush(Stack *stk, elem_t value) {
    // StackVerify

    if (stk->size == stk->capacity) {
        int result = StackResize(stk);
        ASSERTED(StackResize, result, 0, 1);
    }

    stk->data[stk->size] = value;
    stk->size++;

    return 0;
}

int StackPop(Stack *stk, elem_t *var) {
    // StackVerify

    *var = stk->data[stk->size - 1];
    stk->size--;

    if ((stk->size != 0 ) && (stk->capacity / stk->size == 4)) {
        StackResize(stk, DOWN);
    }

    return 0;
}