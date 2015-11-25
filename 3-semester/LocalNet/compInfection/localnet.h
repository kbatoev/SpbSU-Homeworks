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

    Statistics *statistics;
    ISystem **arrayOfSystems;
    int computers;
    int **map;
    QList<int> numbersOfInfected;
};

