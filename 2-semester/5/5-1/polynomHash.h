#pragma once

#include "hashFunction.h"

class PolynomHash : public HashFunction
{
public:

    PolynomHash() : primeNumber(71)
    {}
    PolynomHash(int newPrimeNumber) : primeNumber(newPrimeNumber)
    {}

    ~PolynomHash() {}
    int countHash(const QString &stringToCount, int module);

private:
    int primeNumber;
};

