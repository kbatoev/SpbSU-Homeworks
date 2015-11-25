#pragma once

#include "isystem.h"

class MSystem : public ISystem
{
public:
    MSystem(INumberGenerator* &generator) : ISystem(generator)
    {
        this->infectionAbility = 50;
        this->name = QString("MacOS");
    }
};
