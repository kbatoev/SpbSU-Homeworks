#include "randomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator()
{
    srand(time(NULL));
}

int RandomNumberGenerator::generateNumber()
{
    return rand() % 100 + 1;
}

