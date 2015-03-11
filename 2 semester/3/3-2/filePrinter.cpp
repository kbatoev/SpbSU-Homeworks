#include "filePrinter.h"

FilePrinter::FilePrinter() : size(0)
{}

FilePrinter::FilePrinter(int *newArray, int newSize)
{
    size = newSize;
    array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = newArray[i];
}

FilePrinter::~FilePrinter()
{
    if (size)
        delete[] array;
}

void FilePrinter::print()
{
    const int maxLengthOfFile = 1000;
    std::cout << "Enter name of file:\n";
    char *fileName = new char[maxLengthOfFile];
    std::cin >> fileName;
    std::ofstream out(fileName);
    for (int i = 0; i < size; i++)
        out << array[i] << " ";
    out << "\n";
    std::cout << "Done.\n";
}
