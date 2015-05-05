#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "uniqueList.h"
#include "elementLackError.h"
#include "repetitionError.h"

class ListTest : public QObject
{
    Q_OBJECT
public:
    ListTest(QObject *parent = 0) : QObject(parent)
    {}

private slots:

    void init()
    {
        list = new UniqueList<int>;
    }

    void cleanup()
    {
        delete list;
    }

    void addOneElement()
    {
        list->add(123);
        QVERIFY(list->exists(123));
    }

    void checkSize()
    {
        list->add(78);
        QVERIFY(list->getSize() == 1);
    }

    void removeOneElement()
    {
        list->add(123);
        list->remove(123);
        QVERIFY(!list->exists(123));
    }

    void checkEmptyList()
    {
        try
        {
            list->remove(42);
            QVERIFY(false);
        }
        catch(ElementLackError &error)
        {
            error.print();
        }
    }

    void addTwoEqualElements()
    {
        try
        {
            list->add(75);
            list->add(75);
            QVERIFY(false);
        }
        catch(RepetitionError &error)
        {
            error.print();
        }
    }

    void addDifferentElements()
    {
        for (int i = 0; i < 100; i++)
            list->add(i);
        for (int i = 0; i < 100; i++)
            QVERIFY(list->exists(i));
    }

    void addAndRemove()
    {
        for (int i = 0; i < 100; i++)
            list->add(i);
        for (int i = 99; i >= 0; --i)
            list->remove(i);
        QVERIFY(!list->getSize());
    }

private:
    UniqueList<int> *list;
};
