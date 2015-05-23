#pragma once

#include <QString>
#include <QtTest/QtTest>
#include <QtCore/QObject>
#include "hashFunction.h"
#include "sumHash.h"
#include "polynomHash.h"
#include "oddFUNction.h"

class HashFunctionTest : public QObject
{
    Q_OBJECT
public:
    HashFunctionTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {}

    void cleanup()
    {
        delete function;
    }

    void countPolynom()
    {
        function = new PolynomHash;
        QVERIFY(function->countHash("ab", 100) == 55);
    }

    void countSum()
    {
        function = new SumHash;
        QVERIFY(function->countHash("1234", 500) == 202);
    }

    void addHashFunction()
    {
        function = new OddFUNction;
        QVERIFY(function->countHash("kverty, how many chin-ups required ?", 43) == 42);
    }

private:
    HashFunction *function;
};

