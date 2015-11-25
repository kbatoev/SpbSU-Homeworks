#pragma once

#include "iNumberGenerator.h"

class ConstRandomGenerator : public INumberGenerator
{
public:
    ConstRandomGenerator();
    int generateNumber();

private:
    static const int probabilityOfExactInfection = 0;
};
