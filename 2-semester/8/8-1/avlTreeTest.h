#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "avlTree.h"

class AVLTreeTest : public QObject
{
    Q_OBJECT
public:
    AVLTreeTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        tree = new AVLTree;
    }

    void cleanup()
    {
        delete tree;
    }

    void checkEmptyBag()
    {
        for (int i = 0; i < 1000; i++)
            QVERIFY(!tree->exists(i));
    }

    void addElement()
    {
        tree->addElement(90);
        QVERIFY(tree->exists(90));
    }

    void deleteElementWithNoChildren()
    {
        tree->addElement(78);
        tree->deleteElement(78);
        QVERIFY(!tree->exists(78));
    }
    void deleteElementWithRightChild()
    {
        tree->addElement(5);
        tree->addElement(10);
        tree->deleteElement(5);
        QVERIFY(tree->exists(10) && tree->getTopValue() == 10);
    }

    void deleteElementWithLeftChild()
    {
        tree->addElement(5);
        tree->addElement(4);
        tree->deleteElement(5);
        QVERIFY(tree->exists(4) && tree->getTopValue() == 4);
    }

    void deleteElementWithTwoChildren()
    {
        tree->addElement(5);
        tree->addElement(10);
        tree->addElement(4);
        tree->deleteElement(5);
        QVERIFY(tree->exists(10) && tree->exists(4) &&
                !tree->exists(5) && tree->getTopValue() == 10);
    }

    void addTwoCopiesOfElementAndDeleteThem()
    {
        tree->addElement(42);
        tree->addElement(42);
        tree->deleteElement(42);
        tree->deleteElement(42);
        QVERIFY(!tree->exists(42));
    }

    void addTwoCopiesOfElementAndSaveOne()
    {
        tree->addElement(42);
        tree->addElement(42);
        tree->deleteElement(42);
        QVERIFY(tree->exists(42));
    }

    void rightRotation()
    {
        tree->addElement(7);
        tree->addElement(6);
        tree->addElement(5);
        QVERIFY(tree->getTopValue() == 6);
    }

    void leftRotation()
    {
        tree->addElement(7);
        tree->addElement(8);
        tree->addElement(9);
        QVERIFY(tree->getTopValue() == 8);
    }


private:
    AVLTree *tree;
};
