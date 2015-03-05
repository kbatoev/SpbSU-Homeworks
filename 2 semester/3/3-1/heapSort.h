#pragma once

#include "sorter.h"

class HeapSort : Sorter
{
public:
    HeapSort();
    void sort(int *array, int sizeOfArray);
private:
    void siftUp(int *array, int current);
    void siftDown(int *array, int limit);
    void heapSort(int *array, int sizeOfArray);
};

