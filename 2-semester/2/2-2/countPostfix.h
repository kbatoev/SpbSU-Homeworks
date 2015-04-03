#pragma once

#include "linkedStack.h"

class CountPostfix
{
public:
    CountPostfix();
    ~CountPostfix();
    int countPostfix(char* postfix);

private:
    LinkedStack *stack;
};

