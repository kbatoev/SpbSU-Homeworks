#pragma once

#include <QString>
#include <iostream>

class HashFunction
{
public:
    virtual ~HashFunction() {}
    virtual int countHash(const QString &stringToCount, int module) = 0;
};
