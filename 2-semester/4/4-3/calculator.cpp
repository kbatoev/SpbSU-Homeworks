#include "calculator.h"

Calculator::Calculator() : converter(new ConverterToPostfix), counter(new CountPostfix)
{}

Calculator::~Calculator()
{
    delete converter;
    delete counter;
}

double Calculator::count(const QString &expression)
{
    return counter->countPostfix(converter->convertToPostfix(expression));
}
