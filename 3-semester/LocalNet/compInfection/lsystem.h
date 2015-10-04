#pragma once

#include "isystem.h"

class LSystem : public ISystem
{
public:
    LSystem() : ISystem()
    {
        this->infectionAbility = 20;
        this->name = QString("LinuxOS");
    }
};
