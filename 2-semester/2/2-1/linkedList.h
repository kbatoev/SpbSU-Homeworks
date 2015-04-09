#pragma once

#include "list.h"

#include <iostream>

class LinkedList : List
{
public:
    LinkedList();
    ~LinkedList();
    void add(int value);
    bool remove(int value);
    void printList();

private:
    class ListElement
    {
    public:
        int value;
        ListElement *next;
        ListElement();
        ListElement(int newValue, ListElement *newNext);
    };
    ListElement *head;
};
