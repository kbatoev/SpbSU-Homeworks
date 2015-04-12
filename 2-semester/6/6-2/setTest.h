#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "set.h"

class SetTest : public QObject
{
    Q_OBJECT
public:
    SetTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        set = new Set<int>;
    }

    void cleanup()
    {
        delete set;
    }

    void addOneElement()
    {
        set->add(100);
        QVERIFY(set->getSize() == 1);
    }

    void addTwoElements()
    {
        set->add(100);
        set->add(56);
        QVERIFY(set->getSize() == 2);
    }
    void addAndDelete()
    {
        set->add(100);
        set->remove(100);
        QVERIFY(set->getSize() == 0);
    }

    void existence()
    {
        set->add(1234);
        QVERIFY(set->exists(1234));
    }

    void unite()
    {
        set->add(1);
        Set<int> *secondSet = new Set<int>;
        secondSet->add(2);
        Set<int> *result = set->uniteSets(secondSet);
        QVERIFY(result->exists(1) && result->exists(2) &&
                secondSet->getSize() == 1 && set->getSize() == 1);
        delete secondSet;
        delete result;
    }

    void intersect()
    {
        set->add(1);
        set->add(56);
        Set<int> *secondSet = new Set<int>;
        secondSet->add(56);
        secondSet->add(890);
        Set<int> *result = set->intersectSets(secondSet);
        QVERIFY(result->getSize() == 1 && result->exists(56));
        delete secondSet;
        delete result;
    }

private:
    Set<int> *set;
};
