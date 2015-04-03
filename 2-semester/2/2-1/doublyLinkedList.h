#pragma once

#include "list.h"
#include <iostream>

class DoublyLinkedList : List
{
private:
    class ListElement
    {
    public:
        int value;
        ListElement *next;
        ListElement *previous;
        ListElement();
        ListElement(int newValue, ListElement *newNext, ListElement *newPrevious);
    };

    ListElement *head;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void add(int value);
    bool remove(int value);
    void printList();
};

