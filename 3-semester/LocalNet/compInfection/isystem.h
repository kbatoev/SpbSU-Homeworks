#pragma once

#include <stdlib.h>
#include <time.h>
#include <QString>

/**
 * @brief The ISystem class
 * Interface that gives opportunity to define degree of defence
 */

class ISystem
{
public:
    ISystem();
    ~ISystem() {}

    void tryToInfectNeighbour(ISystem *neighbour, int shift);
    void makeJustInfected();
    void makeInfected();

    bool isInfected();
    bool isHealthy();
    bool isJustInfected();

    int getInfectionAbility();
    QString getQStringStatus();
    QString getName();

    enum HealthState
    {
        Healthy = 1,
        JustInfected,
        Infected
    };

protected:
    HealthState state;
    QString name;
    int infectionAbility;
};

