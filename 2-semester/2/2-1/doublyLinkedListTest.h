#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "doublyLinkedList.h"

class DoublyLinkedListTest : public QObject
{
    Q_OBJECT

public:
    DoublyLinkedListTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        doublyList = new DoublyLinkedList;
    }

    void cleanup()
    {
        delete doublyList;
    }

    void addOneElement()
    {
        doublyList->add(3);
        QVERIFY(doublyList->getFirst() == 3);
    }

    void addTwoElements()
    {
        doublyList->add(-100500);
        doublyList->add(100500);
        QVERIFY(doublyList->getFirst() == 100500);
    }

    void addManyElements()
    {
        doublyList->add(1);
        doublyList->add(0);
        doublyList->add(78);
        doublyList->add(123);
        doublyList->add(-198989);
        QVERIFY(doublyList->getFirst() == -198989);
    }

    void removeFromNothing()
    {
        QVERIFY(!doublyList->remove(900));
    }

    void removeAfterAdding()
    {
        doublyList->add(900);
        QVERIFY(doublyList->remove(900));
    }

    void multiRemove()
    {
        doublyList->add(1);
        doublyList->add(0);
        doublyList->add(78);
        doublyList->add(123);
        doublyList->add(-198989);
        QVERIFY(doublyList->remove(1) && doublyList->remove(0) &&
                doublyList->remove(78) && doublyList->remove(123) && doublyList->remove(-198989));
    }

private:
    DoublyLinkedList *doublyList;
};
