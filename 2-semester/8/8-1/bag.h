#pragma once

#include "avlTree.h"

template <typename T>
class Bag
{
public:
    Bag() : tree(new AVLTree<T>())
    {}
    ~Bag()
    {
        delete tree;
    }

    void addElement(const T &value)
    {
        tree->addElement(value);
    }
    void deleteElement(const T &value)
    {
        tree->deleteElement(value);
    }

    bool exists(const T &value)
    {
        return tree->exists(value);
    }

    T getTopValue()
    {
        return tree->getTopValue();
    }

    void print()
    {
        tree->print();
    }

private:
    AVLTree<T> *tree;
};
