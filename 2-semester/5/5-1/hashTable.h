#pragma once

#include <QString>
#include "list.h"
#include "hashFunction.h"

/**
 * @brief The HashTable class
 * ATD - Hash Table. It's used
 */

class HashTable
{
public:

    HashTable();
    /// constructor that sets hash function
    HashTable(int hash(const QString &, int));
    ~HashTable();

    void addString(QString stringToAdd);
    bool deleteString(const QString &stringToDelete);
    bool findString(const QString &stringToFind);

    /// shows you dialog to choose one
    void chooseHashFunction();

    /// sets new function and refreshes hashTable
    void changeHashFunction(int hash(const QString &, int));


    /// prints on console some data: load factor, number of collisions, words added ...
    void showStatistics();



private:

    void refreshTable();
    LinkedList<QString>** createTable(int size);

    HashFunction *function;
    LinkedList<QString> **hashTable;
    int hashTableSize;

};

