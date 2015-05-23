#include "sumHash.h"

int SumHash::countHash(const QString &stringToCount, int module)
{
    int sum = 0;
    for (int i = 0; i < stringToCount.size(); i++)
    {
        int symbolCode = stringToCount[i].unicode();
        sum  += symbolCode;
        sum %= module;
    }

    if (sum < 0)
        sum += module;
    return sum;
}
