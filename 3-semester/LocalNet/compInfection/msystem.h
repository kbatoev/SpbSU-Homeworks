#pragma once

#include "isystem.h"

class MSystem : public ISystem
{
public:
    MSystem() : ISystem()
    {
        this->infectionAbility = 50;
        this->name = QString("MacOS");
    }
};
