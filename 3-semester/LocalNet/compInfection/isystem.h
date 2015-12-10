#pragma once

#include <QString>
#include "iNumberGenerator.h"

/**
 * @brief The ISystem class
 * Interface that gives opportunity to define degree of defence
 */

class ISystem
{
public:
    ISystem(INumberGenerator* &generator);
    ~ISystem();

    void wasAttacked();

    void makeJustInfected();
    void makeInfected();

    bool isInfected();
    bool isHealthy();
    bool isJustInfected();

    QString getQStringStatus();
    QString getName();

    enum HealthState
    {
        healthy = 1,
        justInfected,
        infected
    };

protected:

    HealthState state;
    QString name;
    int infectionAbility;
    INumberGenerator *numberGenerator;
};

