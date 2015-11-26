#pragma once

#include <iostream>
#include <QList>

#include "isystem.h"
#include "msystem.h"
#include "lsystem.h"
#include "wsystem.h"

#include "iNumberGenerator.h"
#include "randomNumberGenerator.h"
#include "statistics.h"

#include "stableneterror.h"

const int firstComputer = 0;
const int maxIterations = 1e+5;

class LocalNet
{
public:
    LocalNet(int computers, int **matrix, int *os, INumberGenerator *generator = 0);
    ~LocalNet();

    void startExperiment();
    void showStatistics();
    int getIterationsCount();
    bool isInfected();

    enum OS
    {
        MOS = 1,
        LOS,
        WOS
    };

private:
    void addStatistics(int iteration);
    void renewStatusOfSystems();
    void makeMap(int **matrix);

    bool infected;
    INumberGenerator *generator;
    Statistics *statistics;
    ISystem **arrayOfSystems;
    int computers;
    int **map;
    QList<int> numbersOfInfected;
};

