#pragma once

#include <iostream>
#include "comparable.h"

/**
 * @brief The LinkedList class
 * Habitual list with method compareTo
 */

class LinkedList : public Comparable
{
public:

    LinkedList();
    ~LinkedList();

    /**
     * @brief add. Method adding new ListElement
     * @param number - value of new ListElement
     */
    void add(const int &number);

    /**
     * @brief remove. It removes a ListElement which value is number
     * @param number
     * @return true, if he could find such element, and false otherwise
     */
    bool remove(const int &number);

    /**
     * @brief print. Method shows List's Elements
     */
    void print();

    LinkedList* cloneYourself();

    /**
     * @brief compareTo. Compares list with something that can be compared by its size
     */
    int compareTo(Comparable *that);
    int getSize();

private:
    class ListElement
    {
    public:
        ListElement();
        ListElement(int value, ListElement *next);
        int value;
        ListElement *next;
    };

    ListElement *head;
    int size;
};

