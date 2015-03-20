#pragma once

#include <iostream>
#include "comparable.h"

class LinkedList : public Comparable
{
public:
    LinkedList();
    ~LinkedList();
    void add(int number);
    bool remove(int number);


    void print();
    LinkedList* cloneYourself();
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

