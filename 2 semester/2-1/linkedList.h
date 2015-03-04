#pragma once

#include "list.h"

#include <iostream>

class LinkedList : List
{
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

public:
    LinkedList();
    ~LinkedList();
    void add(int value);
    bool remove(int value);
    void printList();
};
