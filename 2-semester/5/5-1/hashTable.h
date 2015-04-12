#pragma once

#include <QString>
#include "list.h"
#include "hashFunction.h"


class HashTable
{
public:

    HashTable();
    HashTable(int hash(const QString &, int));
    ~HashTable();


    void addString(QString stringToAdd);

    bool deleteString(const QString &stringToDelete);
    bool findString(const QString &stringToFind);

    void chooseHashFunction();

    void changeHashFunction(int hash(const QString &, int));

    void showStatistics();



private:

    void refreshTable();
    LinkedList<QString>** createTable(int size);

    HashFunction *function;
    LinkedList<QString> **hashTable;
    int hashTableSize;

};

