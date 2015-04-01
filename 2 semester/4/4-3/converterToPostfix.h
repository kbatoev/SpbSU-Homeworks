#pragma once

#include <QString>
#include "linkedStack.h"

class ConverterToPostfix
{
public:
    ConverterToPostfix();
    ~ConverterToPostfix();
    QString convertToPostfix(QString infix);

private:
    LinkedStack *stack;
};
