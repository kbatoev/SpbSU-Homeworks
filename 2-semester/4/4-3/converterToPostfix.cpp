#include "converterToPostfix.h"

const char space = ' ';
const int maxSize = 1000;

ConverterToPostfix::ConverterToPostfix() : stack(new LinkedStack)
{}

ConverterToPostfix::~ConverterToPostfix()
{
    delete stack;
}

enum Token
{
    openedBracket = 0,
    closedBracket = 1,
    addition = 2,
    subtraction = 3,
    multiplication = 4,
    division = 5,
    blank = 6,
    figure = 7
};

Token determineToken(QChar symbol)
{
    QChar variants[7] = {'+', '-', '*', '/', '(', ')', ' '};
    Token determination[7] = {addition, subtraction, multiplication,
                           division, openedBracket, closedBracket, blank};

    for (int i = 0; i < 7; i++)
        if (symbol == variants[i])
            return determination[i];
    return figure;
}

void checkSpaceInPostfix(QString postfix, int &current)
{
    if (postfix[current - 1] != space)
        postfix[current++] = space;
}

int countPriority(int action)
{
    return action / 2;
}

char transformTokenToChar(int currentToken)
{
    switch(currentToken)
    {
    case 2: return '+';
    case 3: return '-';
    case 4: return '*';
    case 5: return '/';
    }
}

QString ConverterToPostfix::convertToPostfix(QString infix)
{
    QString postfix = "";

    int current = 0;
    int i = 0;
    while (infix[i] != '\0')
    {
        Token token = determineToken(infix[i]);
        switch (token)
        {
        case figure: postfix[current++] = infix[i];
            break;
        case openedBracket: stack->push((int)openedBracket);
            break;
        case closedBracket:
            while (stack->top() != (int)openedBracket)
            {
                int currentToken = stack->top();
                checkSpaceInPostfix(postfix, current);
                char action = transformTokenToChar(currentToken);
                postfix[current++] = action;
                postfix[current++] = space;
                stack->pop();
            }
            stack->pop();
            break;
        case blank:
            checkSpaceInPostfix(postfix, current);
            break;
        default:
            int currentAction = (int)token;
            checkSpaceInPostfix(postfix, current);
            while (!stack->isEmpty() && countPriority(stack->top()) >= countPriority(currentAction))
            {
                char action = transformTokenToChar((int)stack->top());
                postfix[current++] = action;
                postfix[current++] = space;
                stack->pop();
            }
            stack->push(currentAction);
            break;
        }
        i++;
    }

    checkSpaceInPostfix(postfix, current);
    while (!stack->isEmpty())
    {
        char action = transformTokenToChar((int)stack->top());
        postfix[current++] = action;
        postfix[current++] = space;
        stack->pop();
    }

    postfix[current] = '\0';

    return postfix;
}
