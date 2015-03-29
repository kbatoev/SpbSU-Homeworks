#include "calculator.h"

Calculator::Calculator() : firstArgument(0), secondArgument(0), action(plus)
{}

void Calculator::changeFirstArgument(int value)
{
    firstArgument = value;
}

void Calculator::changeSecondArgument(int value)
{
    secondArgument = value;
}

void Calculator::changeAction(QString arg)
{
    if (arg == "+")
        action = plus;
    if (arg == "-")
        action = minus;
    if (arg == "*")
        action = multiplication;
    if (arg == "/")
        action = division;
}

void Calculator::countExpression()
{
    switch (action)
    {
    case plus: result = firstArgument + secondArgument;
        break;

    case minus: result = firstArgument - secondArgument;
        break;

    case multiplication: result = firstArgument * secondArgument;
        break;

    case division:
        if (secondArgument)
            result = firstArgument / secondArgument;
        break;

    default:
        break;
    }
}

bool Calculator::isCorrectExpression()
{
    return !(secondArgument == 0 && action == division);
}

int Calculator::getResult()
{
    return result;
}
