#pragma once

#include "sorter.h"

/**
 * @brief The QuickSort class
 * Class inherited from Sorter
 */

class QuickSort : Sorter
{
public:

    QuickSort();

    /// realization of function in Sorter
    void sort(int *array, int sizeOfArray);

private:

    /// Quick sort
    /// @param left - first index of unsorted area
    /// @param right - last index of unsorted area
    void quickSort(int *array, int left, int right);
};

