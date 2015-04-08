#pragma once

#include <QString>
#include "linkedStack.h"

/**
 * @brief The CountPostfix class
 */

class CountPostfix
{
public:

    CountPostfix();
    ~CountPostfix();

    /**
     * @brief countPostfix - counts result of maths expression
     * @param postfix
     * @return value
     */
    double countPostfix(const QString &postfix);

private:
    LinkedStack *stack;
};

