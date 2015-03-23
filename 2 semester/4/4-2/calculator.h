#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

class Calculator
{
public:
    Calculator();

    // changes
    void changeFirstArgument(int value);
    void changeSecondArgument(int value);
    void changeAction(QString arg);

    // recount
    void countExpression();

    // functions for work with files mainWindow
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
