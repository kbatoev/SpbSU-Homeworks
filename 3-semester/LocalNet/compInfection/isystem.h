#pragma once
#include <stdlib.h>
#include <time.h>
#include <QString>

class ISystem
{
public:
    ISystem();
    ~ISystem() {}
    void tryToInfectYorself(int infectorsProbability);

    bool getStatus();
    int getInfectionAbility();
    QString getQStringStatus();
    QString getName();

protected:
    QString name;
    int infectionAbility;
    bool isInfected;
};

