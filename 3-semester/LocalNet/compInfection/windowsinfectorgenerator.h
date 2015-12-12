#pragma once

#include "iNumberGenerator.h"

class WindowsInfectorGenerator : public INumberGenerator
{
public:
    WindowsInfectorGenerator();
    int generateNumber();
private:
    static const int windowsProbabilityOfInfection = 70;
};
