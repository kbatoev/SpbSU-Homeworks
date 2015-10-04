#pragma once

#include <iostream>
#include <QList>
#include "isystem.h"


class LocalNet
{
public:
    LocalNet(int computers, int **matrix, int *os);
    ~LocalNet();

    void startExperiment();
    enum OS
    {
        MOS = 1,
        LOS,
        WOS
    };

private:
    void showStatistics(int iteration);

    ISystem **arrayOfSystems;
    int computers;
    int **map;
    QList<int> numbersOfUninfected;
};

