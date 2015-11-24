/*

#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "localnet.h"

class LocalNetTest : public QObject
{
    Q_OBJECT
public:
    LocalNetTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void checkNetConsistingOfOneSystem()
    {
        int size = 1;
        createArraysWithGivenSize(size);
        matrix[0][0] = 0;
        os[0] = 1;
        net = new LocalNet(size, matrix, os);
        net->startExperiment();
        emptyMemory(size);
        QVERIFY(net->getIterationNumber() == 1);
    }

    void checkNetConsistingOfTwoSystems()
    {
        int size = 2;
        createArraysWithGivenSize(size);
        matrix[0][0] = matrix[1][1] = 0;
        matrix[0][1] = matrix[1][0] = 1;
        os[0] = os[1] = 2;
        net = new LocalNet(size, matrix, os, probabilityOfExactInfection);
        net->startExperiment();
        emptyMemory(size);
        QVERIFY(net->getIterationNumber() == 2);
    }

    void checkBigNet()
    {
        int size = 4;
        createArraysWithGivenSize(size);
        int stackArray[4][4] = {{0, 0, 1, 1},
                                {0, 0, 0, 1},
                                {1, 0, 0, 0},
                                {1, 1, 0, 0}};

        int stackOS[4] = {1, 1, 1, 1};
        for (int i = 0; i < size; i++)
            os[i] = stackOS[i];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                matrix[i][j] = stackArray[i][j];
        net = new LocalNet(size, matrix, os, probabilityOfExactInfection);
        net->startExperiment();
        emptyMemory(size);
        QVERIFY(net->getIterationNumber() == 3);
    }

private:
    void createArraysWithGivenSize(int size)
    {
        matrix = new int*[size];
        os = new int[size];
        for (int i = 0; i < size; i++)
            matrix[i] = new int[size];
    }

    void emptyMemory(int size)
    {
        for (int i = 0; i < size; i++)
            delete[] matrix[i];
        delete[] matrix;
        delete[] os;
    }

    int** matrix;
    int* os;
    LocalNet *net;
};
*/
