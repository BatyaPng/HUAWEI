#include "Stack/Stack.hpp"

int main() {
    Stack stk = {};

    StackCtor(&stk, 5);

    printf("%lg\n", stk.data[1]); 

    StackDtor(&stk);
}