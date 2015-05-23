#pragma once

#include <QtTest/QtTest>
#include <QtCore/QObject>
#include "comparable.h"
#include "linkedList.h"

enum compareResult
{
    less = -1,
    equal,
    more
};

class ComparableTest : public QObject
{
    Q_OBJECT
public:
    ComparableTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void compareEmptyLists()
    {
        LinkedList *first = new LinkedList;
        LinkedList *second = new LinkedList;
        QVERIFY(second->compareTo(first) == equal);
        delete first;
        delete second;
    }

    void compareTwoLists()
    {
        LinkedList *first = new LinkedList;
        LinkedList *second = new LinkedList;
        first->add(5);
        QVERIFY(first->compareTo(second) == more);
        delete first;
        delete second;
    }

    void compareListsAfterDeletingElement()
    {
        LinkedList *first = new LinkedList;
        LinkedList *second = new LinkedList;
        first->add(5);
        first->remove(5);
        QVERIFY(first->compareTo(second) == equal);
        delete first;
        delete second;
    }

    void compareBigLists()
    {
        LinkedList *first = new LinkedList;
        LinkedList *second = new LinkedList;

        for (int i = 0; i < 100; i++)
            first->add(i);
        for (int i = 0; i < 105; i++)
            second->add(i);

        QVERIFY(first->compareTo(second) == less);

        delete second;
        delete first;
    }

};
