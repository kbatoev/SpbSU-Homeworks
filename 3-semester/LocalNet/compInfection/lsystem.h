#pragma once

#include "isystem.h"

class LSystem : public ISystem
{
public:
    LSystem(INumberGenerator *generator) : ISystem(generator)
    {
        this->infectionAbility = 20;
        this->name = QString("LinuxOS");
    }
};
