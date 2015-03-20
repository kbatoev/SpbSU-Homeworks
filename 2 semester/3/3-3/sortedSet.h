#pragma once
#include "comparable.h"
#include <iostream>

class SortedSet
{
public:
    SortedSet();
    ~SortedSet();
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

