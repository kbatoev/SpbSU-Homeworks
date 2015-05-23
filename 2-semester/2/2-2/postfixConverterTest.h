#pragma once

#include <QString>
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "converterToPostfix.h"

const int areEqual = 0;

class ConverterToPostfixTest : public QObject
{
    Q_OBJECT
public:
    ConverterToPostfixTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        converter = new ConverterToPostfix;
    }

    void cleanup()
    {
        delete converter;
    }

    void countEasy()
    {
        QVERIFY(strcmp(converter->convertToPostfix("1"), "1 ") == areEqual);
    }

    void countSimple()
    {
        QVERIFY(strcmp(converter->convertToPostfix("1+100"),"1 100 + ") == areEqual);
    }

    void countMedium()
    {
        QVERIFY(strcmp(converter->convertToPostfix("(50 - 100) / 10"), "50 100 - 10 / ") == areEqual);
    }

    void countHard()
    {
        QVERIFY(strcmp(converter->convertToPostfix("(10+5)*(17-7) - (12+3)*(50/5)"),
                       "10 5 + 17 7 - * 12 3 + 50 5 / * - ") == areEqual);
    }


private:
    ConverterToPostfix *converter;
};
