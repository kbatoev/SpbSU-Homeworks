#pragma once

#include "sorter.h"

/**
 * @brief The MergeSort class
 * Class inherited of Sorter
 */

class MergeSort : Sorter
{
public:

    /// constructor
    MergeSort();

    /// realization of function in Sorter
    void sort(int *array, int sizeOfArray);

private:

    /// merge sort
    /// @param left - first index of unsorted area
    /// @param right - last index of unsorted area
    int* mergeSort(int* array, int first, int last);
};
