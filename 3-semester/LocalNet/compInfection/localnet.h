#pragma once

#include <iostream>
#include <QList>
#include "isystem.h"

const int firstComputer = 0;
const int probabilityOfExactInfection = 200;

class LocalNet
{
public:
    LocalNet(int computers, int **matrix, int *os);
    /**
     * @brief LocalNet
     * @param addition - can increase probability of infection
     */
    LocalNet(int computers, int **matrix, int *os, int addition); // for Tests
    ~LocalNet();

    void startExperimentWithOutput();
    void startExperiment();

    /**
     * @brief getIterationNumber - used for Tests
     */
    int getIterationNumber();
    enum OS
    {
        MOS = 1,
        LOS,
        WOS
    };

private:
    void showStatistics();
    /**
     * @brief renewSystemsStatus
     * switches Systems from JustInfected to Infected
     */
    void renewSystemsStatus();

    ISystem **arrayOfSystems;
    int iteration;
    int computers;
    int addingProbability;
    int **map;
    QList<int> numbersOfInfected;
};

