#pragma once

#include "isystem.h"

class WSystem : public ISystem
{
public:
    WSystem() : ISystem()
    {
        this->infectionAbility = 70;
        this->name = QString("WindowsOS");
    }
};
