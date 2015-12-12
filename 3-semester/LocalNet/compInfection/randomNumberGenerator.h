#pragma once

#include <stdlib.h>
#include <time.h>
#include "iNumberGenerator.h"

class RandomNumberGenerator : public INumberGenerator
{
public:
    RandomNumberGenerator();
    /// produces number in interval [1 ... 100]
    int generateNumber();
};

