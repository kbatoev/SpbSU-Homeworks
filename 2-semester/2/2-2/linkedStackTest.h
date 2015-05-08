#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "linkedStack.h"

class LinkedStackTest : public QObject
{
    Q_OBJECT
public:
    LinkedStackTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        linkedStack = new LinkedStack;
    }

    void cleanup()
    {
        delete linkedStack;
    }

    void isEmptyStack()
    {
        QVERIFY(linkedStack->isEmpty());
    }

    void topOfEmptyStack()
    {
        QVERIFY(linkedStack->top() == 0);
    }

    void pushOneElement()
    {
        linkedStack->push(2);
        QVERIFY(linkedStack->top() == 2);
    }

    void pushTwoElements()
    {
        linkedStack->push(2);
        linkedStack->push(90);
        int topElement = linkedStack->top();
        linkedStack->pop();
        QVERIFY(topElement == 90 && linkedStack->top() == 2);
    }

    void pushAndTop()
    {
        for (int i = 0; i < 500; i++)
            linkedStack->push(i + 1);

        QVERIFY(linkedStack->top() == 500);
    }

    void pushManyElements()
    {
        for (int i = 0; i < 100; ++i)
            linkedStack->push(i);
        for (int i = 99; i >= 0; i--)
        {
            QVERIFY(linkedStack->top() == i);
            linkedStack->pop();
        }
    }

    void pushAndDeleteManyElements()
    {
        for (int i = 0; i < 100; i++)
            linkedStack->push(i);

        for (int i = 0; i < 100; i++)
            linkedStack->pop();

        QVERIFY(linkedStack->isEmpty());
    }

private:
    LinkedStack *linkedStack;
};
