#pragma once

#include <QString>
#include "linkedStack.h"

/**
 * @brief The CountPostfix class
 */

class CountPostfix
{
public:

    /// constructor
    CountPostfix();

    /// destructor
    ~CountPostfix();

    /**
     * @brief countPostfix - counts result of maths expression
     * @param postfix
     * @return value
     */
    double countPostfix(QString postfix);

private:
    LinkedStack *stack;
};

