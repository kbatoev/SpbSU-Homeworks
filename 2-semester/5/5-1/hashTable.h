#pragma once

#include <QString>
#include "list.h"
#include "hashFunction.h"
#include "sumHash.h"
#include "polynomHash.h"
#include "oddFUNction.h"

/**
 * @brief The HashTable class
 * ATD - Hash Table. It's used
 */

class HashTable
{
public:

    HashTable();
    ~HashTable();

    void addString(const QString &stringToAdd);
    bool deleteString(const QString &stringToDelete);
    bool findString(const QString &stringToFind);

    /// shows you dialog to choose one
    void chooseHashFunction();

    /// sets new function and refreshes hashTable
    void changeHashFunction(HashFunction *newFunction);


    /// prints on console some data: load factor, number of collisions, words added ...
    void showStatistics();

private:

    void refreshTable();
    LinkedList<QString>** createTable(int size);

    HashFunction *function;
    LinkedList<QString> **hashTable;
    int hashTableSize;
};

