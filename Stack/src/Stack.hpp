#ifndef _STACK_H_
#define _STACK_H_

#define DEBUG
#define HASH_PROT

#include "CommonFunction.hpp"
#include <math.h>

enum STACK_ERROR_CODES {
    NP_STACK                = 0b0000001,    
    NP_DATA                 = 0b0000010,    
    POISON_DATA             = 0b0000100,    
    CAPACITY_LESS_SIZE      = 0b0001000,
    LEFT_CANARY_DAMAGED     = 0b0010000,        
    RIGHT_CANARY_DAMAGED    = 0b0100000,
    BAD_HASH                = 0b1000000,
    errorsNumber    
}; 

static const char *errorNames[] = {
    "Null pointer to stack",
    "Null pointer to stack data",
    "Poison stack",
    "Capacity less size",
    "Left canary damaged",
    "Right canary damaged",
    "Bad hash"
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
        const char *fileName;
        const char *funcName;
        size_t lineNumber;
        const char *varName;
    };
#endif

struct Stack {
    elem_t *data;
    size_t size;
    size_t capacity;

    #ifdef DEBUG
        struct VarInfo VarInfo = {};
    #endif 

    #ifdef HASH_PROT
        size_t *hashP = NULL;
    #endif
};

#ifdef DEBUG
    #define VAR_INFO_PARAM , const char *fileName, const char *funcName, const size_t lineNumber, const char *varName
    #define VAR_INFO(varName) , __FILE__, __func__, __LINE__, #varName + 1
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

int StackVerify(const Stack *stk);

int StackDumpFunc(const Stack stk , FILE* streamOut VAR_INFO_PARAM);

void StackErrorOut(int errorCode, FILE *streamOut);

#endif