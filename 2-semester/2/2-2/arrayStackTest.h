#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "arrayStack.h"

class ArrayStackTest : public QObject
{
    Q_OBJECT
public:
    ArrayStackTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        arrayStack = new ArrayStack;
    }

    void cleanup()
    {
        delete arrayStack;
    }

    void isEmptyStack()
    {
        QVERIFY(arrayStack->isEmpty());
    }

    void topOfEmptyStack()
    {
        QVERIFY(arrayStack->top() == 0);
    }

    void pushOneElement()
    {
        arrayStack->push(2);
        QVERIFY(arrayStack->top() == 2);
    }

    void pushTwoElements()
    {
        arrayStack->push(2);
        arrayStack->push(90);
        int topElement = arrayStack->top();
        arrayStack->pop();
        QVERIFY(topElement == 90 && arrayStack->top() == 2);
    }

    void pushAndTop()
    {
        for (int i = 0; i < 500; i++)
            arrayStack->push(i + 1);

        QVERIFY(arrayStack->top() == 500);
    }

    void pushManyElements()
    {
        for (int i = 0; i < 100; ++i)
            arrayStack->push(i);
        for (int i = 99; i >= 0; i--)
        {
            QVERIFY(arrayStack->top() == i);
            arrayStack->pop();
        }
    }

    void pushAndDeleteManyElements()
    {
        for (int i = 0; i < 100; i++)
            arrayStack->push(i);

        for (int i = 0; i < 100; i++)
            arrayStack->pop();

        QVERIFY(arrayStack->isEmpty());
    }

private:
    ArrayStack *arrayStack;
};
