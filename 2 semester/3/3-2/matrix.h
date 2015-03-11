#pragma once

#include <iostream>

class Matrix
{
public:
    Matrix();
    Matrix(int matrixSize);
    ~Matrix();
    void fillMatrix();
    void printMatrix();
    void passMatrixSpirally(int *resultArray);

private:
    int **array;
    int size;
};
