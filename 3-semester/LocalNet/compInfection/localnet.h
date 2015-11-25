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

const int firstComputer = 0;

class LocalNet
{
public:
    LocalNet(int computers, int **matrix, int *os, INumberGenerator *generator = 0);
    ~LocalNet();

    void startExperiment();
    void showStatistics();
    int getIterationsCount();

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

    INumberGenerator *generator;
    Statistics *statistics;
    ISystem **arrayOfSystems;
    int computers;
    int **map;
    QList<int> numbersOfInfected;
};

