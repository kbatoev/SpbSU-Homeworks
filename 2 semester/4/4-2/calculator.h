#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

/**
 * @brief The Calculator class
 * Implementation of simple calculator
 */


class Calculator
{
public:

    Calculator();

    /**
     * @brief changeFirstArgument.
     * Set new value to first operand
     */
    void changeFirstArgument(int value);

    /**
     * @brief changeSecondArgument.
     * Set new value to second operand.
     */
    void changeSecondArgument(int value);

    /**
     * @brief changeAction. Set new action to operation
     * @param action
     */
    void changeAction(const QString &action);

    /**
     * @brief countExpression. Gets a result from given expression
     */
    void countExpression();

    /**
     * @brief isCorrectExpression
     * @return true if math's expression is valid, and false otherwise
     */
    bool isCorrectExpression();

    int getResult();

private:
    enum Operations
    {
        plus = 1,
        minus,
        multiplication,
        division
    };

    int firstArgument;
    int secondArgument;
    Operations action;
    int result;
};

#endif // CALCULATOR_H
