#pragma once

#include "list.h"
#include <iostream>

class DoublyLinkedList : List
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void add(int value);
    bool remove(int value);
    void printList();
    int getFirst();
    bool exists(int value);

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
};

