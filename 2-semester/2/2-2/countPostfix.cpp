#include "countPostfix.h"

const char space = ' ';

CountPostfix::CountPostfix()
{
    stack = new LinkedStack;
}

CountPostfix::~CountPostfix()
{
    delete stack;
}

int createIntNumber(char *postfix, int& i)
{
    int number = 0;
    while (postfix[i] != space)
        number = number * 10 + postfix[i++] - '0';
    return number;
}

int countOperator(int first, int second, char action)
{
    switch (action)
    {
    case '+': return first + second;
    case '-': return first - second;
    case '*': return first * second;
    case '/': return first / second;
    }
}

bool isNumber(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

int CountPostfix::countPostfix(char *postfix)
{
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (postfix[i] != space)
        {
            if (isNumber(postfix[i]))
            {
                int number = createIntNumber(postfix, i);
                stack->push(number);
            }
            else
            {
                int second = stack->top();
                stack->pop();
                int first = stack->top();
                stack->pop();
                int third = countOperator(first, second, postfix[i]);
                stack->push(third);
            }
        }
        i++;
    }

    return stack->top();
}
