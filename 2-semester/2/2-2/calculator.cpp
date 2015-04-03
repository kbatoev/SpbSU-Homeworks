#include "calculator.h"

Calculator::Calculator()
{
    converter = new ConverterToPostfix;
    counter = new CountPostfix;
}

Calculator::~Calculator()
{
    delete converter;
    delete counter;
}

int Calculator::countExpression(char *expression)
{
    char *postfix = converter->convertToPostfix(expression);
    int result = counter->countPostfix(postfix);
    delete postfix;
    return result;
}
