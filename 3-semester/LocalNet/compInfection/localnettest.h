#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "localnet.h"
#include "constrandomgenerator.h"
#include "stableneterror.h"
#include "windowsinfectorgenerator.h"

class LocalNetTest : public QObject
{
    Q_OBJECT
public:
    LocalNetTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void checkStableSystem()
    {
        int size = 2;
        createArraysWithGivenSize(size);
        matrix[0][0] = matrix[1][1] = 0;
        matrix[0][1] = matrix[1][0] = 1;
        os[0] = os[1] = 2;
        LocalNet *net = new LocalNet(size, matrix, os, new WindowsInfectorGenerator());
        try
        {
            net->startExperiment();
        }
        catch(StableNetError error)
        {
            error.comment();
        }
        QVERIFY(!net->isInfected());
        emptyMemory(size);
    }

    void checkNetConsistingOfTwoSystems()
    {
        int size = 2;
        createArraysWithGivenSize(size);
        matrix[0][0] = matrix[1][1] = 0;
        matrix[0][1] = matrix[1][0] = 1;
        os[0] = os[1] = 2;
        LocalNet *net = new LocalNet(size, matrix, os, new ConstRandomGenerator());
        net->startExperiment();

        QVERIFY(net->getIterationsCount() == 2);
        emptyMemory(size);
    }

    void checkNetConsistingOfOneSystem()
    {
        int size = 1;
        createArraysWithGivenSize(size);
        matrix[0][0] = 0;
        os[0] = 1;
        LocalNet *net = new LocalNet(size, matrix, os, new ConstRandomGenerator());
        net->startExperiment();
        QVERIFY(net->getIterationsCount() == 1);
        emptyMemory(size);
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

        LocalNet *net = new LocalNet(size, matrix, os, new ConstRandomGenerator());
        net->startExperiment();

        QVERIFY(net->getIterationsCount() == 3);
        emptyMemory(size);
    }

private:
    void createArraysWithGivenSize(int size)
    {
        os = new int[size];
        matrix = new int*[size];
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
};
