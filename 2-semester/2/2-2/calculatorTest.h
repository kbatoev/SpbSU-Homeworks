#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "calculator.h"

class CalculatorTest : public QObject
{
    Q_OBJECT
public:
    CalculatorTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        calculator = new Calculator;
    }

    void cleanup()
    {
        delete calculator;
    }

    void countEasy()
    {
        QVERIFY(calculator->countExpression("1") == 1);
    }

    void countSimple()
    {
        QVERIFY(calculator->countExpression("1+100") == 101);
    }

    void countMedium()
    {
        QVERIFY(calculator->countExpression("(50 - 100) / 10") == -5);
    }

    void countHard()
    {
        QVERIFY(calculator->countExpression("(10+5)*(17-7) - (12+3)*(50/5)") == 0);
    }

private:
    Calculator *calculator;
};
