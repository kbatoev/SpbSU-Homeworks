#pragma once

#include "state.h"
#include <stdlib.h>
#include <time.h>
#include <QString>

/**
 * @brief The ISystem class
 * Interface that gives opportunity to define degree of defence
 */

class ISystem : public State
{
public:
    ISystem();
    ~ISystem() {}

    void tryToInfectNeighbour(ISystem *neighbour, int split);
    void makeJustInfected();
    void makeInfected();

    bool isInfected();
    bool isHealthy();
    bool isJustInfected();

    int getInfectionAbility();
    QString getQStringStatus();
    QString getName();

protected:
    QString name;
    int infectionAbility;
};

