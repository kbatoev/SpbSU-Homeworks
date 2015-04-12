#include "hashFunction.h"

HashFunction::HashFunction()
{
    addedFunctions[0] = countHashPolynom;
    addedFunctions[1] = countHashSum;
    hashFunction = countHashPolynom;
    numberOfAdded = 2;
}

HashFunction::~HashFunction()
{
    hashFunction = nullptr;
}

void HashFunction::changeHashFunction()
{
    int choice = 0;
    std::cout << "Enter:\n0 to choose SumHash\n1 to choose PolynomHash \n2 to choose user's hashFunction\n";
    std::cin >> choice;

    switch (choice)
    {
    case sum:
        hashFunction = countHashSum;
        break;
    case polynom:
        hashFunction = countHashPolynom;
        break;

    case user:
        std::cout << "There are " << numberOfAdded - 2 << " hashFunctions\n";
        std::cout << "Which one would you like ?\n";
        int number = 0;
        std::cin >> number;
        if (number > 0)
            hashFunction = addedFunctions[number + 1];
        break;
    }
}

void HashFunction::changeHashFunction(int index)
{
    if (index < numberOfAdded)
        hashFunction = addedFunctions[index];
}

void HashFunction::setLastFunction()
{
    hashFunction = addedFunctions[numberOfAdded - 1];
}

void HashFunction::addUsersHashFunction(int hash(const QString &, int))
{
    if (numberOfAdded < 100)
        addedFunctions[numberOfAdded++] = hash;
}

int HashFunction::countHashPolynom(const QString &stringToCount, int module)
{
    int primeNumber = 71;
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

int HashFunction::countHashSum(const QString &stringToCount, int module)
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
