#include "src/Stack.hpp"

int main() {
    Stack stk = {};
    
    StackCtor(&stk, 5);

    for (double i = 0; i < 7; i++) {
        StackPush(&stk, i);
    }

    StackDump(stk, stdout);

    for (double i = 0; i < 7; i++) {
        elem_t var = NAN;
        StackPop(&stk, &var);
    }


    StackDtor(&stk);
}