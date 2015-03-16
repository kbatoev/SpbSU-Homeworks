#pragma once

#include <iostream>
#include "listsComparator.h"

class LinkedList : public ListsComparator
{
public:
    LinkedList();
    ~LinkedList();
    void add(int value);
    bool remove(int value);
    void printList();
    int compareTo(ListsComparator* list);
    int getSizeOfList();
    LinkedList* cloneList();
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
    int size;
};
