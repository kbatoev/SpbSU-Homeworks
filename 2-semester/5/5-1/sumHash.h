#pragma once

#include "hashFunction.h"

class SumHash : public HashFunction
{
public:
    SumHash() {}
    ~SumHash() {}
    int countHash(const QString &stringToCount, int module);
};

