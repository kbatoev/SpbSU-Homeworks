#include <iostream>
#include "matrix.h"
#include "consolePrinter.h"
#include "filePrinter.h"

using namespace std;

int main()
{
    int sizeOfMatrix = 0;
    cout << "Enter an odd size of matrix: ";
    cin >> sizeOfMatrix;

    Matrix *matrix = new Matrix(sizeOfMatrix);
    matrix->fill();
    cout << "That's your matrix: \n";
    matrix->show();

    int *spiralArray = matrix->transformSpirally();
    int arraySize = sizeOfMatrix * sizeOfMatrix;

    ConsolePrinter consoleWriter(spiralArray, arraySize);
    consoleWriter.print();

    FilePrinter fileWriter(spiralArray, arraySize);
    fileWriter.print();

    delete[] spiralArray;
    delete matrix;
    return 0;
}

