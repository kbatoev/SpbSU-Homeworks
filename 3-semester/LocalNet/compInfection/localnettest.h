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
    LocalNetTest(QObject *parent = 0) : QObject(parent)
    {
        index = 0;
    }

private slots:

    void init()
    {
        os = new int[sizes[index]];
        matrix = new int*[sizes[index]];
        for (int i = 0; i < sizes[index]; i++)
            matrix[i] = new int[sizes[index]];
    }

    void cleanup()
    {
        for (int i = 0; i < sizes[index]; i++)
            delete[] matrix[i];
        delete[] matrix;
        delete[] os;
        index++;
    }

    void checkStableSystem()
    {
        int size = sizes[index];
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
    }

    void checkNetConsistingOfTwoSystems()
    {
        int size = sizes[index];
        matrix[0][0] = matrix[1][1] = 0;
        matrix[0][1] = matrix[1][0] = 1;
        os[0] = os[1] = 2;
        LocalNet *net = new LocalNet(size, matrix, os, new ConstRandomGenerator());
        net->startExperiment();

        QVERIFY(net->getIterationsCount() == 2);
    }

    void checkNetConsistingOfOneSystem()
    {
        int size = sizes[index];
        matrix[0][0] = 0;
        os[0] = 1;
        LocalNet *net = new LocalNet(size, matrix, os, new ConstRandomGenerator());
        net->startExperiment();
        QVERIFY(net->getIterationsCount() == 1);
    }

    void checkBigNet()
    {
        int size = sizes[index];
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
    }

private:
    int sizes[4] = {2, 2, 1, 4};
    int index;
    int** matrix;
    int* os;
};
