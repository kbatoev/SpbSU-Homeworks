#pragma once

/**
 * @brief The Sorter class
 * Interface of sortings classes
 */

class Sorter
{
public:

    virtual ~Sorter() {}

    /// virtual method sort
    /// @param array - array that needs sorting
    /// @param sizeOfArray - elements in array
    virtual void sort(int *array, int sizeOfArray) = 0;
};

