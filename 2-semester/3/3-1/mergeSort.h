#pragma once

#include "sorter.h"

class MergeSort : Sorter
{
public:
    MergeSort();
    void sort(int *array, int sizeOfArray);
private:
    int* mergeSort(int* array, int first, int last);
};
