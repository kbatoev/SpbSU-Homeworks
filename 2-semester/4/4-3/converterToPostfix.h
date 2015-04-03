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

    /// constructor
    ConverterToPostfix();

    /// destructor
    ~ConverterToPostfix();

    /**
     * @brief convertToPostfix
     * @param infix
     * @return postfix string
     */
    QString convertToPostfix(QString infix);

private:
    LinkedStack *stack;
};
