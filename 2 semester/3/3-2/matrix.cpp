#include "matrix.h"

Matrix::Matrix() : size(0)
{}

Matrix::Matrix(int matrixSize)
{
    size = matrixSize;
    array = new int*[size];
    for (int i = 0; i < size; i++)
        array[i] = new int[size];
}

Matrix::~Matrix()
{
    for (int i = 0; i < size; i++)
        delete[] array[i];
    delete[] array;
}

void Matrix::fillMatrix()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            array[i][j] = size * i + j + 1;
}

void Matrix::printMatrix()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            std::cout << array[i][j] << " ";
        std::cout << "\n";
    }
}

void Matrix::passMatrixSpirally(int *resultArray)
{
    int current = 0;

    int curI = size / 2;
    int curJ = size / 2;
    resultArray[current++] = array[curI][curJ];

    int countOfIterations = size / 2;

    const int sides = 4;
    int verticalSteps[sides] = {-1, 0, 1, 0};
    int horizontalSteps[sides] = {0, -1, 0, 1};
    int step = 2;
    for (int i = 0; i < countOfIterations; i++)
    {
        for (int j = 0; j < sides; j++)
        {
            for (int k = 0; k < step; k++)
            {
                if (!k && !j)
                    curJ++;
                else
                {
                    curI += verticalSteps[j];
                    curJ += horizontalSteps[j];
                }
                resultArray[current++] = array[curI][curJ];
            }
        }
        step += 2;
    }
}
