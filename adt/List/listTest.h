#pragma once
#include <iostream>
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "list.h"

class ListTest : public QObject
{
    Q_OBJECT
public:
    ListTest(QObject *parent = 0): QObject(parent)
    {}

private slots:

    void init()
    {
        list = new LinkedList<int>;
    }

    void cleanup()
    {
        delete list;
    }

    void removeZero()
    {
        QVERIFY(!list->remove(0));
    }

    void addValues()
    {
        list->add(7);
        list->add(5);
        list->add(10);
    }

    void removeValue()
    {
        list->add(2);
        QVERIFY(list->remove(2));
    }


public:
    LinkedList<int> *list;
};
