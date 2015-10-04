#include "isystem.h"

ISystem::ISystem() : isInfected(false)
{
    srand(time(NULL));
}

bool ISystem::getStatus()
{
    return isInfected;
}

int ISystem::getInfectionAbility()
{
    return infectionAbility;
}

QString ISystem::getQStringStatus()
{
    if (isInfected)
        return QString("Infected");
    else
        return QString("Healthy");
}

QString ISystem::getName()
{
    return name;
}

void ISystem::tryToInfectYorself(int infectorsProbability)
{
    int chance = rand() % 100 + 1;
    isInfected = (2 * chance <= infectorsProbability + infectionAbility);
}
