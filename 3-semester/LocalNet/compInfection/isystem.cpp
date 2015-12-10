#include "isystem.h"

ISystem::ISystem(INumberGenerator* &generator)
{
    numberGenerator = generator;
    state = healthy;
}

ISystem::~ISystem()
{
}

void ISystem::wasAttacked()
{
    int chance = numberGenerator->generateNumber();
    if (chance <= infectionAbility)
        this->makeJustInfected();
}

void ISystem::makeJustInfected()
{
    state = justInfected;
}

void ISystem::makeInfected()
{
    state = infected;
}

bool ISystem::isInfected()
{
    return state == infected;
}

bool ISystem::isHealthy()
{
    return state == healthy;
}

bool ISystem::isJustInfected()
{
    return state == justInfected;
}

QString ISystem::getQStringStatus()
{
    switch (state)
    {
        case healthy:
            return QString("Healthy");

        case justInfected:
            return QString("Just Infected");

        case infected:
            return QString("Infected");
    }
}

QString ISystem::getName()
{
    return name;
}
