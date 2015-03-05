#pragma once

#include "sorter.h"

class QuickSort : Sorter
{
public:
    QuickSort();
    void sort(int *array, int sizeOfArray);

private:
    void quickSort(int *array, int left, int right);
};

