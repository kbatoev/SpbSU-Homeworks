#pragma once

#include "list.h"

#include <iostream>

using namespace std;

class LinkedList : List
{
private:
    class ListElement
    {
    public:
        int value;
        ListElement *next;
        ListElement();
        ListElement(int nValue, ListElement *nNext);
    };
    ListElement *head;

public:
    LinkedList();
    ~LinkedList();
    void add(int value);
    bool remove(int value);
    void printList();
};
