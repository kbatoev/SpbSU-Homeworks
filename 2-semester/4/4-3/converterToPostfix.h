#pragma once

#include <QString>
#include "linkedStack.h"

/**
 * @brief The ConverterToPostfix class
 * Converts expression from infix to postfix
 */

class ConverterToPostfix
{
public:

    ConverterToPostfix();
    ~ConverterToPostfix();

    /**
     * @brief convertToPostfix
     * transforms to postfix notation because it's easy to count
     */
    QString convertToPostfix(const QString &infix);

private:
    LinkedStack *stack;
};
