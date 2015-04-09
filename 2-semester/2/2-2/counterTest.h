#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "countPostfix.h"

class CounterTest : public QObject
{
    Q_OBJECT
public:
    CounterTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        counter = new CountPostfix;
    }

    void cleanup()
    {
        delete counter;
    }

    void countEasy()
    {
        QVERIFY(counter->countPostfix("1") == 1);
    }

    void countSimple()
    {
        QVERIFY(counter->countPostfix("1 100 + ") == 101);
    }

    void countMedium()
    {
        QVERIFY(counter->countPostfix("50 100 - 10 /") == -5);
    }

    void countHard()
    {
        QVERIFY(counter->countPostfix("10 5 + 17 7 - * 12 3 + 50 5 / * -") == 0);
    }


private:
    CountPostfix *counter;
};
