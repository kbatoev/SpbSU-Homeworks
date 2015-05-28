#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "bag.h"

class BagTest : public QObject
{
    Q_OBJECT
public:
    BagTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        bag = new Bag<int>;
    }

    void cleanup()
    {
        delete bag;
    }

    void checkEmptyBag()
    {
        for (int i = 0; i < 1000; i++)
            QVERIFY(!bag->exists(i));
    }

    void addElement()
    {
        bag->addElement(90);
        QVERIFY(bag->exists(90));
    }


    void deleteElementWithNoChildren()
    {
        bag->addElement(78);
        bag->deleteElement(78);
        QVERIFY(!bag->exists(78));
    }
    void deleteElementWithRightChild()
    {
        bag->addElement(5);
        bag->addElement(10);
        bag->deleteElement(5);
        QVERIFY(bag->exists(10) && bag->getTopValue() == 10);
    }

    void deleteElementWithLeftChild()
    {
        bag->addElement(5);
        bag->addElement(4);
        bag->deleteElement(5);
        QVERIFY(bag->exists(4) && bag->getTopValue() == 4);
    }

    void deleteElementWithTwoChildren()
    {
        bag->addElement(5);
        bag->addElement(10);
        bag->addElement(4);
        bag->deleteElement(5);
        QVERIFY(bag->exists(10) && bag->exists(4) &&
                !bag->exists(5) && bag->getTopValue() == 10);
    }

    void addTwoCopiesOfElementAndDeleteThem()
    {
        bag->addElement(42);
        bag->addElement(42);
        bag->deleteElement(42);
        bag->deleteElement(42);
        QVERIFY(!bag->exists(42));
    }

    void addTwoCopiesOfElementAndSaveOne()
    {
        bag->addElement(42);
        bag->addElement(42);
        bag->deleteElement(42);
        QVERIFY(bag->exists(42));
    }

    void rightRotation()
    {
        bag->addElement(7);
        bag->addElement(6);
        bag->addElement(5);
        QVERIFY(bag->getTopValue() == 6);
    }

    void leftRotation()
    {
        bag->addElement(7);
        bag->addElement(8);
        bag->addElement(9);
        QVERIFY(bag->getTopValue() == 8);
    }

private:
    Bag<int> *bag;
};

