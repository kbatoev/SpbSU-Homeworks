#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "linkedList.h"


class LinkedListTest : public QObject
{
    Q_OBJECT
public:
    LinkedListTest(QObject *parent = 0): QObject(parent)
    {}

private slots:

    void init()
    {
        linkedList = new LinkedList;
    }

    void cleanup()
    {
        delete linkedList;
    }

    void existFunction()
    {
        QVERIFY(!linkedList->exists(89));
    }

    void addOneElement()
    {
        linkedList->add(3);
        QVERIFY(linkedList->getFirst() == 3);
    }

    void addTwoElements()
    {
        linkedList->add(-100500);
        linkedList->add(100500);
        QVERIFY(linkedList->getFirst() == 100500 && linkedList->exists(-100500));
    }

    void addManyElements()
    {
        linkedList->add(1);
        linkedList->add(0);
        linkedList->add(78);
        linkedList->add(123);
        linkedList->add(-198989);
        QVERIFY(linkedList->getFirst() == -198989 && linkedList->exists(123) && linkedList->exists(78)
                && linkedList->exists(0) && linkedList->exists(1));
    }

    void removeFromNothing()
    {
        QVERIFY(!linkedList->remove(900));
    }

    void removeAfterAdding()
    {
        linkedList->add(900);
        QVERIFY(linkedList->remove(900));
    }

    void multiRemove()
    {
        linkedList->add(1);
        linkedList->add(0);
        linkedList->add(78);
        linkedList->add(123);
        linkedList->add(-198989);
        QVERIFY(linkedList->remove(1) && linkedList->remove(0) &&
                linkedList->remove(78) && linkedList->remove(123) && linkedList->remove(-198989));
    }

private:
    LinkedList *linkedList;
};

