#include "isystem.h"

ISystem::ISystem()
{
    srand(time(NULL));
    state = Healthy;
}

void ISystem::tryToInfectNeighbour(ISystem *neighbour, int shift)
{
    int chance = rand() % 100 + 1;
    if (2 * chance <= neighbour->getInfectionAbility() + infectionAbility + shift)
        neighbour->makeJustInfected();
}

void ISystem::makeJustInfected()
{
    state = JustInfected;
}

void ISystem::makeInfected()
{
    state = Infected;
}

bool ISystem::isInfected()
{
    return state == Infected;
}

bool ISystem::isHealthy()
{
    return state == Healthy;
}

bool ISystem::isJustInfected()
{
    return state == JustInfected;
}

int ISystem::getInfectionAbility()
{
    return infectionAbility;
}

QString ISystem::getQStringStatus()
{
    switch (state)
    {
        case Healthy:
            return QString("Healthy");
        case JustInfected:
            return QString("Just Infected");
        case Infected:
            return QString("Infected");
    }
}

QString ISystem::getName()
{
    return name;
}
