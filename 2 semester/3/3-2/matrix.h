#pragma once

#include <iostream>

/**
 * @brief The Matrix class
 * Class appointed to a work with two-dimensional arrays
 */

class Matrix
{
public:

    /// constructors
    Matrix();
    Matrix(int sizeOfMatrix);

    /// destructor
    ~Matrix();

    /// method fill
    /// it fills up matrix with natural numbers
    void fill();

    /// method show
    /// it shows you a matrix
    void show();

    /// method transformSpirally
    /// it creates new array filled with elements of initial matrix with spiral bypass
    int* transformSpirally();

private:
    int** matrix;
    int size;
};

