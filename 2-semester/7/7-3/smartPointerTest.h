#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "smartPointer.h"

class SmartPointerTest : public QObject
{
    Q_OBJECT
public:
    SmartPointerTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void createIntPointer()
    {
        SmartPointer<int> pointer(new int(150));
        QVERIFY(*pointer.getOriginPointer() == 150);
        QVERIFY(pointer.getNumberOfLinks() == 1);
    }

    void copyConstructor()
    {
        SmartPointer<int> pointer(new int(9));
        SmartPointer<int> pointer1(pointer);
        QVERIFY(pointer1.getNumberOfLinks() == 2 && pointer.getNumberOfLinks() == 2);
    }
    void checkLinksNumberChanging()
    {
        SmartPointer<int> pointer(new int(9));
        SmartPointer<int> pointer1(new int(17));
        pointer = pointer1;
        QVERIFY(*pointer.getOriginPointer() == 17);
    }

    void checkArrayPointer()
    {
        int *array = new int[3] {15, 16, 90};
        SmartPointer<int> pointer(array);
        QVERIFY(pointer.getOriginPointer()[2] == 90);
    }

};
