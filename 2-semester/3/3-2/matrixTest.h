#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "matrix.h"

class MatrixTest : public QObject
{
    Q_OBJECT
public:
    MatrixTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void checkOneElementMatrix()
    {
        int result[1] = {1};
        matrix = new Matrix(1);
        matrix->fill();
        int *byPass = matrix->transformSpirally();
        QVERIFY(areEqualArrays(result, byPass, 1));
        delete byPass;
        delete matrix;
    }

    void checkMatrix()
    {
        int result[9] = {5, 6, 3, 2, 1, 4, 7, 8, 9};
        int sizeOfMatrix = 3;
        matrix = new Matrix(sizeOfMatrix);
        matrix->fill();
        int *byPass = matrix->transformSpirally();
        QVERIFY(areEqualArrays(result, byPass, 9));
        delete byPass;
        delete matrix;
    }


private:
    bool areEqualArrays(int *first, int *second, int size)
    {
        for (int i = 0; i < size; i++)
            if (first[i] != second[i])
                return false;
        return true;
    }

    Matrix *matrix;
};
