#pragma once

#include <QString>
#include "linkedStack.h"

class CountPostfix
{
public:
    CountPostfix();
    ~CountPostfix();
    double countPostfix(QString postfix);

private:
    LinkedStack *stack;
};

