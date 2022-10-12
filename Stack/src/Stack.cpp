#include "Stack.hpp"

#define POISON NAN
#define POISON_SPECIFIER "lg"

#define DEBUG
#define CANARY_PROT
#define HASH_PROT

#ifdef CANARY_PROT
    #define ON_CANARY_PROT(...) __VA_ARGS__
    #define CANARY_SIZE sizeof(long double)
#else 
    #define ON_CANARY_PROT(...) 
#endif

#ifdef HASH_PROT
    #define ON_HASH_PROT(...) __VA_ARGS__
    #define CALCULATE_HASH(stk) *(stk->hashP) = HashFAQ6(&stk, sizeof(stk));
#else 
    #define ON_HASH_PROT(...)
    #define CALCULATE_HASH(...) 
#endif

int StackCtorFunc(Stack *stk, elem_t value VAR_INFO_PARAM) {
    ASSERTED(NP, stk, NULL, NP_PASSED);

    #ifdef DEBUG
        stk->VarInfo.fileName = fileName;
        stk->VarInfo.funcName = funcName;
        stk->VarInfo.lineNumber = lineNumber;
        stk->VarInfo.varName = varName;
    #endif

    void *tmp = calloc(1, FIRST_CAPACITY_STACK * sizeof(elem_t) ON_CANARY_PROT(+ 2 * CANARY_SIZE));
    ASSERTED(calloc, tmp, NULL, CALLOC_FAILED);

    stk->data = (elem_t *) ((char *) tmp ON_CANARY_PROT(+ CANARY_SIZE));

    for (int i = 0; i < FIRST_CAPACITY_STACK; i++) {
        stk->data[i] = POISON;
    }

    stk->capacity = FIRST_CAPACITY_STACK;
    stk->data[stk->size++] = value;

    #ifdef HASH_PROT
        stk->hashP = (size_t *) calloc(1, sizeof(size_t));
        ASSERTED(calloc, stk, NULL, CALLOC_FAILED);
        CALCULATE_HASH(stk);
    #endif

    return 0;
}

int StackDtor(Stack *stk) {
    // StackVerify;

    for (size_t i = 0; i < stk->capacity; i++) {
        stk->data[i] = POISON;
    }

    free((char *) stk->data ON_CANARY_PROT(- CANARY_SIZE));

    return 0;
}

static int StackResize(Stack *stk, MODE_STACK_RESIZE mode) {
    // StackVerify;

    void *tmpBuf = NULL;
    ON_CANARY_PROT(stk->data = (elem_t *) ((char *) stk->data - CANARY_SIZE));
    
    if (mode == UP) {
        ON_CANARY_PROT(size_t alignment = (CANARY_SIZE > sizeof(elem_t)) ? sizeof(elem_t) : CANARY_SIZE);

        tmpBuf = realloc(stk->data, 2 * (stk->capacity) * sizeof(elem_t) ON_CANARY_PROT(+ CANARY_SIZE + alignment));
        ASSERTED(realloc, tmpBuf, NULL, REALLOC_FAILED);

        stk->data = (elem_t *) ((char *) tmpBuf ON_CANARY_PROT(+ CANARY_SIZE));
        stk->capacity *= 2;
    } else {
        tmpBuf = realloc(stk->data, stk->capacity  / 2 * sizeof(elem_t) ON_CANARY_PROT(+ 2 * CANARY_SIZE));
        ASSERTED(realloc, tmpBuf, NULL, REALLOC_FAILED);

        stk->data = (elem_t *) ((char *) tmpBuf ON_CANARY_PROT(+ CANARY_SIZE));
        stk->capacity /= 2;
    }

    for (size_t i = stk->size; i < stk->capacity; i++) {
        (stk->data)[i] = POISON;
    }

    CALCULATE_HASH(stk);

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

    CALCULATE_HASH(stk);

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
        return NULL_SIZE_STACK;
    }

    CALCULATE_HASH(stk);

    return 0;
}

int StackDumpFunc(const Stack stk , FILE* streamOut VAR_INFO_PARAM) {
    // StackVerify

    #ifdef DEBUG
        ASSERTED(NP, funcName, NULL, NP_PASSED);
        ASSERTED(NP, fileName, NULL, NP_PASSED);
    #endif

    ASSERTED(NP, streamOut, NULL, NP_PASSED);

    fprintf(streamOut, "================================================================\n");
    
    #ifdef DEBUG
        fprintf(streamOut, "%s() at %s(%ld):\n", funcName, fileName, lineNumber);
        fprintf(streamOut, "Stack[%p] (ok) \"%s\" at %s() at %s(%ld)\n\n", &stk, stk.VarInfo.varName, stk.VarInfo.funcName, stk.VarInfo.fileName, stk.VarInfo.lineNumber);
    #endif

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

