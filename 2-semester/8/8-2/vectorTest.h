#pragma once

#include <QtTest/QtTest>
#include <QtCore/QObject>
#include "vector.h"

class VectorTest : public QObject
{
    Q_OBJECT
public:
    VectorTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        array1 = new int[2] {1, 25};
        array2 = new int[2] {-1, 100};
    }

    void cleanup()
    {
        delete array1;
        delete array2;
    }

    void sumOfVectors()
    {
        Vector<int> vector1(2, array1);
        Vector<int> vector2(2, array2);

        Vector<int> sum = vector1 + vector2;
        int *sumArray = new int[2] {0, 125};
        Vector<int> result(2, sumArray);

        delete[] sumArray;
        QVERIFY(sum == result);
    }

    void differenceOfVectors()
    {
        Vector<int> vector1(2, array1);
        Vector<int> vector2(2, array2);

        Vector<int> difference = vector1 - vector2;
        int *differenceArray = new int[2] {2, -75};
        Vector<int> result(2, differenceArray);

        delete[] differenceArray;
        QVERIFY(difference == result);
    }

    void copyVector()
    {
        Vector<int> vector1(2, array1);

        Vector<int> copy(vector1);
        int *copyArray = new int[2] {1, 25};
        Vector<int> result(2, copyArray);

        delete[] copyArray;
        QVERIFY(copy == result);
    }

    void isZero()
    {
        Vector<int> emptyVector;
        QVERIFY(emptyVector.isZeroVector());
    }

    void scalarProduct()
    {
        Vector<int> vector1(2, array1);
        Vector<int> vector2(2, array2);
        int product = vector1 * vector2;
        QVERIFY(product == 2499 && !vector1.isZeroVector() && !vector2.isZeroVector());
    }

private:
    int *array1;
    int *array2;
};
