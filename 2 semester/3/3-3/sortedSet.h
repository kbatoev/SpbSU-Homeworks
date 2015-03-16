#pragma once

#include "listsComparator.h"
#include "linkedList.h"

class SortedSet
{
public:
    SortedSet();
    ~SortedSet();
    int getSizeOfSet();
    void addList(LinkedList *newList);
    void printSet();

private:
    class SetElement
    {
    public:
        SetElement();
        SetElement(LinkedList *newList, SetElement *nextList);
        LinkedList *list;
        SetElement *next;
    };

    SetElement *head;
    int sizeOfSet;
};
