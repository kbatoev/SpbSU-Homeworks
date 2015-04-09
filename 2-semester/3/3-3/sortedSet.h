#pragma once

#include "comparable.h"
#include <iostream>

/**
 * @brief The SortedSet class
 * class imitates structure that keeps something comparable
 */

class SortedSet
{
public:

    SortedSet();
    ~SortedSet();

    /// add something that can be compared to
    void add(Comparable *newElement);

    void print();

private:

    class SetElement
    {
    public:
        SetElement();
        SetElement(Comparable *element, SetElement *next);
        Comparable *element;
        SetElement *next;
    };

    SetElement *top;
};

