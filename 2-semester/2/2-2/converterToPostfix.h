#pragma once

#include "linkedStack.h"

class ConverterToPostfix
{
public:
    ConverterToPostfix();
    ~ConverterToPostfix();
    char* convertToPostfix(char *infix);

private:
    LinkedStack *stack;
};
