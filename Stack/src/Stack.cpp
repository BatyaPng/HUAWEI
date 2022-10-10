#include "Stack.hpp"

// #define DEBUG

#define POISON NAN
#define POISON_SPECIFIER "lg"

int StackCtorFunc(Stack *stk, elem_t value VAR_INFO_PARAM) {
    ASSERTED(NP, stk, NULL, 1);

    #ifdef DUBUG
        stk->VarInfo.fileName = fileName;
        stk->VarInfo.funcName = funcName;
        stk->VarInfo.lineNumber = lineNumber;
        stk->VarInfo.varName = varName;
    #endif

    stk->data = (elem_t *) calloc(FIRST_CAPACITY_STACK, sizeof(elem_t));
    ASSERTED(calloc, stk->data, NULL, 2);

    for (int i = 0; i < FIRST_CAPACITY_STACK; i++) {
        stk->data[i] = POISON;
    }

    stk->capacity = FIRST_CAPACITY_STACK;
    stk->size++;
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

static int StackResize(Stack *stk, MODE_STACK_RESIZE mode) {
    // StackVerify;

    void *tmpBuf = NULL;
    
    if (mode == UP) {
        tmpBuf = realloc(stk->data, 2 * (stk->capacity) * sizeof(elem_t));
        ASSERTED(realloc, tmpBuf, NULL, 1);

        stk->data = (elem_t *) tmpBuf;
        stk->capacity *= 2;
    } else {
        tmpBuf = realloc(stk->data, (stk->capacity)  / 2 * sizeof(elem_t));
        ASSERTED(realloc, tmpBuf, NULL, 1);

        stk->data = (elem_t *) tmpBuf;
        stk->capacity /= 2;
    }

    for (size_t i = stk->size; i < stk->capacity; i++) {
        (stk->data)[i] = POISON;
    }

    return 0;     
}

int StackPush(Stack *stk, elem_t value) {
    // StackVerify

    if (stk->size == stk->capacity) {
        int result = StackResize(stk, UP);
        ASSERTED(StackResize, result, 1, 1);
    }

    stk->data[stk->size] = value;
    stk->size++;

    return 0;
}

int StackPop(Stack *stk, elem_t *var) {
    // StackVerify

    if (stk->size != 0) {
        *var = stk->data[stk->size - 1];
        stk->size--;

        if ((stk->size != 0 ) && (stk->capacity / stk->size == 4)) {
            StackResize(stk, DOWN);
        }
    } else {
        return 1;
    }

    return 0;
}

int StackDumpFunc(const Stack stk , FILE* streamOut VAR_INFO_PARAM) {
    // StackVerify

    ASSERTED(NP, funcName, NULL, NP_PASSED);
    ASSERTED(NP, fileName, NULL, NP_PASSED);
    ASSERTED(NP, streamOut, NULL, NP_PASSED);

    fprintf(streamOut, "================================================================\n");
    
    fprintf(streamOut, "%s at %s(%ld):\n", funcName, fileName, lineNumber);
    fprintf(streamOut, "Stack[%p] (ok) \"%s\" at \"%s\" at %s(%ld)\n\n", &stk, stk.VarInfo.varName, stk.VarInfo.funcName, stk.VarInfo.fileName, stk.VarInfo.lineNumber);

    fprintf(streamOut, "size = %lu\n", stk.size);
    fprintf(streamOut, "capacity = %lu\n", stk.capacity);
    fprintf(streamOut, "\ndata[%p] {\n", (void *) &stk.data);

    for (size_t i = 0; i < stk.size; i++) {
        fprintf(streamOut, "    [%lu] = %" POISON_SPECIFIER "\n", i, stk.data[i]);
    }

    for (size_t i = stk.size; i < stk.capacity; i++) {
        fprintf(streamOut, "    [%lu] = POISON\n", i);
    }

    fprintf(streamOut, "}\n");

    return 0;
}