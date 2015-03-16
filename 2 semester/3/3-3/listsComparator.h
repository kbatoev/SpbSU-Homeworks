#pragma once

class ListsComparator
{
public:
    ~ListsComparator() {}
    virtual int compareTo(ListsComparator *list) = 0;
    virtual int getSizeOfList() = 0;
};
