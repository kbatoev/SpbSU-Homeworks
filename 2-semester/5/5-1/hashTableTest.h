#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "hashTable.h"
#include "hashFunction.h"
#include "polynomHash.h"

class HashTableTest : public QObject
{
    Q_OBJECT
public:
    HashTableTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        table = new HashTable;
    }

    void cleanup()
    {
        delete table;
    }

    void addOneWord()
    {
        table->addString("there's a book on the hashTable");
        QVERIFY(table->findString("there's a book on the hashTable"));
    }

    void addIdenticalWords()
    {
        for (int i = 0; i < 100; i++)
            table->addString(".9qwerTY12'kk");
        for (int i = 0; i < 100; i++)
            QVERIFY(table->deleteString(".9qwerTY12'kk"));
    }

    void deleteFromEmptyHashTable()
    {
        QVERIFY(!table->deleteString("something"));
    }

    void deleteAfterAdding()
    {
        table->addString("sentence is words");
        table->addString("words are sentence");
        QVERIFY(table->deleteString("sentence is words") && !table->deleteString("words is sentence"));
    }

    void findWordAfterAdding()
    {
        table->addString("qwerty");
        table->addString("ololo");
        table->addString("infinity");
        QVERIFY(table->findString("qwerty"));
    }

    void giveStatistics()
    {
        QString sampleString = "";
        for (int i = 0; i < 1000; i++)
        {
            QChar symbol = (i % 26) + 97;
            sampleString += symbol;
            table->addString(sampleString);
        }
        table->showStatistics();
    }

    void chooseFunction()
    {
        table->chooseHashFunction();
    }
    void changeFunction()
    {
        table->addString("test");
        HashFunction *polynom = new PolynomHash;
        table->changeHashFunction(polynom);
        QVERIFY(table->findString("test"));
    }

private:
    HashTable *table;
};
