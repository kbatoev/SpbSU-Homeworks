#pragma once

#include "hashFunction.h"

class OddFUNction : public HashFunction
{
public:
    OddFUNction() {}
    ~OddFUNction() {}
    int countHash(const QString &stringToCount, int module);
};

