#include "hashTable.h"


HashTable::HashTable()
{
    function = new SumHash;
    hashTableSize = 1000;
    hashTable = createTable(hashTableSize);
}

HashTable::~HashTable()
{
    delete function;
    for (int i = 0; i < hashTableSize; i++)
        delete hashTable[i];
    delete hashTable;
}

void HashTable::addString(const QString &stringToAdd)
{
    int index = function->countHash(stringToAdd, hashTableSize);
    hashTable[index]->add(stringToAdd);
}

bool HashTable::deleteString(const QString &stringToDelete)
{
    int index = function->countHash(stringToDelete, hashTableSize);
    bool isRemoved = hashTable[index]->remove(stringToDelete);
    return isRemoved;
}

bool HashTable::findString(const QString &stringToFind)
{
    int index = function->countHash(stringToFind, hashTableSize);
    bool isFound = hashTable[index]->find(stringToFind);
    return isFound;
}

void HashTable::chooseHashFunction()
{
    enum Choice
    {
        sum = 0,
        polynom,
        odd
    };

    int number = 0;
    std::cout << "Enter:\n0 - sumHash\n1 - PolynomHash\n2 - OddFunction\n";
    std::cin >> number;
    delete function;

    switch (number)
    {
    case sum:
        function = new SumHash;
        break;

    case polynom:
        function = new PolynomHash;
        break;
    case odd:
        function = new OddFUNction;
        break;
    }

    refreshTable();
}

void HashTable::changeHashFunction(HashFunction *newFunction)
{
    delete function;
    function = newFunction;
    refreshTable();
}

void HashTable::showStatistics()
{
    int words = 0;
    int maxCollision = 0;
    int numberOfCollisions = 0;
    int emptyCells = 0;
    for (int i = 0; i < hashTableSize; i++)
    {
        words += hashTable[i]->getSize();
        if (hashTable[i]->getCollisionsNumber() > 1)
            numberOfCollisions++;
        if (hashTable[i]->getCollisionsNumber() > maxCollision)
            maxCollision = hashTable[i]->getCollisionsNumber();
        if (!hashTable[i]->getSize())
            emptyCells++;
    }
    double loadFactor = (double)words / (double)hashTableSize;

    std::cout << "Size of hash-Table is: " << hashTableSize << "\n";
    std::cout << "Words added: " << words << "\n";
    std::cout << "Number of collisions: " << numberOfCollisions << "\n";
    std::cout << "Amount of words in MaxCollision is: " << maxCollision << "\n";
    std::cout << "Empty cells: " << emptyCells << "\n";
    std::cout << "Load factor: " << loadFactor << "\n";
}

void HashTable::refreshTable()
{
    LinkedList<QString> **newHashTable = createTable(hashTableSize);
    for (int i = 0; i < hashTableSize; i++)
    {
        for (int j = 0; j < hashTable[i]->getSize(); j++)
        {
            QString currentString = hashTable[i]->getFirstElement();
            hashTable[i]->remove(currentString);
            int index = function->countHash(currentString, hashTableSize);
            newHashTable[index]->add(currentString);
        }
    }
    delete hashTable;
    hashTable = newHashTable;
}

LinkedList<QString> **HashTable::createTable(int size)
{
    LinkedList<QString> **table = new LinkedList<QString>*[size];
    for (int i = 0; i < size; i++)
        table[i] = new LinkedList<QString>;
    return table;
}


