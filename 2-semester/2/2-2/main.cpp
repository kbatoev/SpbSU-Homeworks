#include <iostream>

#include "linkedStack.h"
#include "arrayStack.h"
#include "calculator.h"

#include "arrayStackTest.h"
#include "linkedStackTest.h"
#include "counterTest.h"
#include "postfixConverterTest.h"
#include "calculatorTest.h"

int main()
{
    std::cout << " TESTING OF ARRAYSTACK \n";
    ArrayStackTest arrayTest;
    QTest::qExec(&arrayTest);

    std::cout << "\n\n TESTING OF LINKEDSTACK \n";
    LinkedStackTest stackTest;
    QTest::qExec(&stackTest);

    std::cout << "\n\n TESTING OF COUNTER\n";
    CounterTest counterTest;
    QTest::qExec(&counterTest);

    std::cout << "\n\n TESTING OF CONVERTER \n";
    ConverterToPostfixTest converterTest;
    QTest::qExec(&converterTest);

    std::cout << "\n\n TESTING OF CALCULATOR \n";
    CalculatorTest calculatorTest;
    QTest::qExec(&calculatorTest);

    return 0;
}

