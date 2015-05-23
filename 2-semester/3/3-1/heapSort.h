#pragma once

#include "sorter.h"

/**
 * @brief The HeapSort class
 * Class inherited from Sorter
 */

class HeapSort : Sorter
{
public:

    HeapSort();

    /// sort function
    void sort(int *array, int sizeOfArray);

private:

    /// siftUp method
    /// builds a real heap from array
    void siftUp(int *array, int current);

    /// siftDown method
    /// maintain the structure of heap
    /// @param limit - border of unsorted area
    void siftDown(int *array, int limit);

    /// heapSort method
    void heapSort(int *array, int sizeOfArray);
};

