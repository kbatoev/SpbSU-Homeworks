#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

/**
 * @brief The Calculator class
 * Realization of simple calculator
 */


class Calculator
{
public:
    /**
     * @brief Calculator. Constructor
     */
    Calculator();

    /**
     * @brief changeFirstArgument. Set new value to first operand
     * @param value
     */
    void changeFirstArgument(int value);

    /**
     * @brief changeSecondArgument. Set new value to second operand.
     * @param value
     */
    void changeSecondArgument(int value);

    /**
     * @brief changeAction. Set new action to operation
     * @param action
     */
    void changeAction(QString action);

    /**
     * @brief countExpression. Gets a result from expression given
     */
    void countExpression();

    /**
     * @brief isCorrectExpression
     * @return true if math's expression is valid, and false otherwise
     */
    bool isCorrectExpression();

    /**
     * @brief getResult
     * @return result of math expression
     */
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
