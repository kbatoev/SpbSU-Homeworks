#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "list.h"
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

    void checkEmptyList()
    {
        try
        {
            list->remove(42);
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

    }

    void addAndRemove()
    {
        for (int i = 0; i < 100; i++)
            list->add(i);
        for (int i = 99; i >= 0; --i)
            list->remove(i);
    }

    void cleanup()
    {
        delete list;
    }

private:
    UniqueList<int> *list;
};
