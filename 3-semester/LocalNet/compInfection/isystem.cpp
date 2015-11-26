#include "isystem.h"

ISystem::ISystem(INumberGenerator* &generator)
{
    numberGenerator = generator;
    state = Healthy;
}

ISystem::~ISystem()
{
    if (numberGenerator)
    {
        delete numberGenerator;
        numberGenerator = nullptr;
    }
}

void ISystem::wasAttacked()
{
    int chance = numberGenerator->generateNumber();
    if (chance <= infectionAbility)
        this->makeJustInfected();
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
