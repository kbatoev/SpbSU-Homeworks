#pragma once

#include <QString>
#include "converterToPostfix.h"
#include "countPostfix.h"

class Calculator
{
public:
    Calculator();
    double count(QString expression);

private:
    ConverterToPostfix *converter;
    CountPostfix *counter;
};

