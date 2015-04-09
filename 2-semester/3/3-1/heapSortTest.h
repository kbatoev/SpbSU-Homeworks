#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "heapSort.h"

class HeapSortTest : public QObject
{
    Q_OBJECT
public:
    HeapSortTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        sort = new HeapSort;
    }

    void cleanup()
    {
        delete sort;
    }

    void simpleTest()
    {
        int first[1] = {3};
        int second[1] = {3};
        sort->sort(first, 1);
        QVERIFY(this->areEqualArrays(first, second, 1));
    }

    void mediumTest()
    {
        int first[2] = {3, 2};
        int second[2] = {2, 3};
        sort->sort(first, 2);
        QVERIFY(this->areEqualArrays(first, second, 2));
    }

    void hardTest()
    {
        int first[100];
        int second[100];
        for (int i = 0; i < 100; ++i)
        {
            first[i] = 100 - i;
            second[i] = i + 1;
        }
        sort->sort(first, 100);
        QVERIFY(areEqualArrays(first, second, 100));
    }

private:
    HeapSort *sort;
    bool areEqualArrays(int *firstArray, int *secondArray, int size)
    {
        for (int i = 0; i < size; i++)
            if (firstArray[i] != secondArray[i])
                return false;
        return true;
    }
};

