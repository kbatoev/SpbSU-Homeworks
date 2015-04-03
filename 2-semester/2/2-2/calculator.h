#pragma once

#include "linkedStack.h"
#include "converterToPostfix.h"
#include "countPostfix.h"

class Calculator
{
public:
    Calculator();
    ~Calculator();
    int countExpression(char* expression);
private:
    ConverterToPostfix *converter;
    CountPostfix *counter;
};

