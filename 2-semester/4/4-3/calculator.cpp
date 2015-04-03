#include "calculator.h"

Calculator::Calculator() : converter(new ConverterToPostfix), counter(new CountPostfix)
{}

double Calculator::count(QString expression)
{
    return counter->countPostfix(converter->convertToPostfix(expression));
}
