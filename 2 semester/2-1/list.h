#pragma once

class List
{
public:
    virtual ~List() {}
    virtual void add(int value) = 0;
    virtual bool remove(int value) = 0;
    virtual void printList() = 0;
};
