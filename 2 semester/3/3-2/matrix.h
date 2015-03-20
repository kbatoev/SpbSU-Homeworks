#pragma once

#include <iostream>

class Matrix
{
public:
    Matrix();
    Matrix(int sizeOfMatrix);
    ~Matrix();
    void fill();
    void show();
    int* transformSpirally();

private:
    int** matrix;
    int size;
};

