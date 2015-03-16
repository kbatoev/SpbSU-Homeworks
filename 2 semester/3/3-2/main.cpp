#include <iostream>
#include "matrix.h"
#include "consolePrinter.h"
#include "filePrinter.h"

using namespace std;

int main()
{
    int matrixSize = 0;
    cout << "Enter odd size of matrix: " << endl;
    cin >> matrixSize;

    Matrix *matrix = new Matrix(matrixSize);
    matrix->fillMatrix();
    int elementsCount = matrixSize * matrixSize;
    int *spiralArray = new int[elementsCount];
    cout << "I've created matrix and filled it.\n";
    cout << "This is it: \n";
    matrix->printMatrix();


    matrix->passMatrixSpirally(spiralArray);


    cout << "I've done spiral bypass of elements.\n";
    cout << "How should I show it to you?\n";
    cout << "Press:\n0 - console\n1 - file\n";
    int choice = 0;
    cin >> choice;

    ConsolePrinter *console = new ConsolePrinter(spiralArray, elementsCount);
    FilePrinter *file = new FilePrinter(spiralArray, elementsCount);

    if (choice)
        file->print();
    else
        console->print();

    delete file;
    delete console;
    delete[] spiralArray;
    delete matrix;
    return 0;
}

