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
    /**
     * @brief SortedSet. Constructor
     */
    SortedSet();

    /// destructor
    ~SortedSet();

    /**
     * @brief add. Adds new element to a SortedSet
     * @param newElement - adding new element
     */
    void add(Comparable *newElement);

    /**
     * @brief print. Method prints every element in set
     */
    void print();

private:
    /**
     * @brief The SetElement class
     * realization of class
     */
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

