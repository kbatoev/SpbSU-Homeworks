#include "countPostfix.h"

const char space = ' ';

CountPostfix::CountPostfix() : stack(new LinkedStack)
{}

CountPostfix::~CountPostfix()
{
    delete stack;
}

double createDoubleNumber(QString postfix, int& i)
{
    QString sNumber = "";
    int j = 0;
    while (postfix[i] != space)
        sNumber[j++] = postfix[i++];

    double number = sNumber.toDouble();

    return number;
}

double countOperator(double first, double second, QChar action)
{
    if (action == '+')
        return first + second;
    if (action == '-')
        return first - second;
    if (action == '*')
        return first * second;
    if (action == '/')
        return first / second;
}

bool isNumber(QChar symbol)
{
    return symbol >= '0' && symbol <= '9';
}

double CountPostfix::countPostfix(QString postfix)
{
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (postfix[i] != space)
        {
            if (isNumber(postfix[i]))
            {
                double number = createDoubleNumber(postfix, i);
                stack->push(number);
            }
            else
            {
                double second = stack->top();
                stack->pop();
                double first = stack->top();
                stack->pop();
                double third = countOperator(first, second, postfix[i]);
                stack->push(third);
            }
        }
        i++;
    }
    return stack->top();
}
