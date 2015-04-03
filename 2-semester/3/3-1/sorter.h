#pragma once

class Sorter
{
public:
    virtual ~Sorter() {}
    virtual void sort(int *array, int sizeOfArray) = 0;
};

