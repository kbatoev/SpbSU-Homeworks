#include "matrix.h"

Matrix::Matrix() : size(0), matrix(nullptr)
{}

Matrix::Matrix(int sizeOfMatrix)
{
    size = sizeOfMatrix;
    matrix = new int*[size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
}

Matrix::~Matrix()
{
    for (int i = 0; i < size; i++)
        delete[] matrix[i];

    delete[] matrix;
}

void Matrix::fill()
{
    //std::cout << "Enter a matrix: \n";
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = i*size + j + 1;
}

void Matrix::show()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
}

int *Matrix::transformSpirally()
{
    int *array = new int[size * size];
    int vertPos = size / 2;
    int horPos = size / 2;
    int current = 0;
    array[current++] = matrix[vertPos][horPos];

    const int sides = 4;
    int step = 2;
    int iterations = size / 2;
    int vertSteps[4] = {-1, 0, 1, 0};
    int horSteps[4] = {0, -1, 0, 1};
    for (int i = 0; i < iterations; i++)
    {
        for (int j = 0; j < sides; j++)
            for (int k = 0; k < step; k++)
            {
                if (!j && !k)
                    horPos++;
                else
                {
                    vertPos += vertSteps[j];
                    horPos += horSteps[j];
                }
                array[current++] = matrix[vertPos][horPos];
            }
        step += 2;
    }
    return array;
}
