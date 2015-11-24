#pragma once

#include "isystem.h"

class WSystem : public ISystem
{
public:
    WSystem(INumberGenerator *generator) : ISystem(generator)
    {
        this->infectionAbility = 70;
        this->name = QString("WindowsOS");
    }
};
