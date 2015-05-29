#pragma once

#include <QtTest/QtTest>
#include <QtCore/QObject>
#include "bsTree.h"


class BSTreeTest : public QObject
{
    Q_OBJECT
public:
    explicit BSTreeTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        tree = new BSTree<int>;
    }

    void cleanup()
    {
        delete tree;
    }

    void existsInEmptyTree()
    {
        QVERIFY(!tree->exists(1090));
    }

    void addElement()
    {
        tree->addElement(123);
        QVERIFY(tree->exists(123));
    }

    void addManyElements()
    {
        for (int i = 0; i < 10000; i++)
            tree->addElement(i);
        for (int i = 0; i < 10000; i++)
            QVERIFY(tree->exists(i));
    }

    void deleteElement()
    {
        tree->addElement(78);
        tree->deleteElement(78);
        QVERIFY(!tree->exists(78));
    }


private:
    BSTree<int> *tree;
};

