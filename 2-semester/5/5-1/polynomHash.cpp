#include "polynomHash.h"

int PolynomHash::countHash(const QString &stringToCount, int module)
{
    int factor = 1;
    int sum = 0;
    for (int i = 0; i < stringToCount.size(); i++)
    {
        int symbolCode = stringToCount[i].unicode();
        sum = (sum + factor * symbolCode) % module;
        factor = (factor * primeNumber) % module;
    }

    if (sum < 0)
        sum += module;
    return sum;
}
