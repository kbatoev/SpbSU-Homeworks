#pragma once

#include <QString>
#include <QtTest/QtTest>
#include <QtCore/QObject>
#include "hashFunction.h"

class HashFunctionTest : public QObject
{
    Q_OBJECT
public:
    HashFunctionTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        function = new HashFunction;
    }

    void cleanup()
    {
        delete function;
    }

    void countPolynom()
    {
        /// default hash function - polynom
        QVERIFY(function->hashFunction("ab", 100) == 55);
    }

    void countSum()
    {
        /// sets 1 hashFunction. It's countHashSum
        function->changeHashFunction(1);
        QVERIFY(function->hashFunction("1234", 500) == 202);
    }

    void addHashFunction()
    {
        function->addUsersHashFunction(answerUniverseQuestionHash);
        function->changeHashFunction(2);
        QVERIFY(function->hashFunction("kverty, how many chin-ups required ?", 43) == 42);
    }

    void simpleFunction()
    {
        function->addUsersHashFunction(answerUniverseQuestionHash);
        function->addUsersHashFunction(countStringLength);
        function->changeHashFunction(3);
        QVERIFY(function->hashFunction("testing", 10) == 7);
    }

private:
    HashFunction *function;

    static int answerUniverseQuestionHash(const QString &stringToCount, int module)
    {
        if (module > 42)
            return 42;
        else
            return 0;
    }

    static int countStringLength(const QString &stringToCount, int module)
    {
        return stringToCount.size() % module;
    }

};
