#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <tree.h>

class TreeTest : public QObject
{
    Q_OBJECT
public:
    TreeTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        tree = new Tree;
    }

    void testAddition()
    {
        tree->add((QChar)'+');
        tree->add(78);
        tree->add(-100);
        QVERIFY(tree->count() == -22);
    }

    void testSubtraction()
    {
        tree->add((QChar)'-');
        tree->add(100500);
        tree->add(100000);
        QVERIFY(tree->count() == 500);
    }

    void testMultiplication()
    {
        tree->add((QChar)'*');
        tree->add(0);
        tree->add(891);
        QVERIFY(tree->count() == 0);
    }

    void testDivision()
    {
        tree->add((QChar)'/');
        tree->add(144);
        tree->add(12);
        QVERIFY(tree->count() == 12);
    }

    void testWithNoOperator()
    {
        tree->add(55);
        QVERIFY(tree->count() == 55);
    }

    void countExpression()
    {
        delete tree;
        tree = new Tree((QString)"(+(* 2 1) (/ 8 -4))");
        QVERIFY(tree->count() == 0);
    }

    void cleanup()
    {
        delete tree;
    }

private:
    Tree *tree;
};
