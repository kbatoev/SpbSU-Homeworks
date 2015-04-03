#pragma once

#include <QString>
#include "converterToPostfix.h"
#include "countPostfix.h"

/**
 * @brief The Calculator class
 */

class Calculator
{
public:
    /**
     * @brief Calculator - constructor
     */
    Calculator();

    /**
     * @brief count - function that counts maths expression's value
     * @param expression - maths expression
     * @return - result of calculation
     */
    double count(QString expression);

private:
    /**
     * @brief converter - class that converts expression to postfix
     */
    ConverterToPostfix *converter;

    /**
     * @brief counter - class that counts expression
     */
    CountPostfix *counter;
};

