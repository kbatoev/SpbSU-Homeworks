#include "filePrinter.h"

FilePrinter::FilePrinter() : size(0), array(nullptr)
{}

FilePrinter::FilePrinter(int *newArray, int newSize)
{
    size = newSize;
    array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = newArray[i];
    char *fileName = new char[100];
    std::cout << "Enter a name of file: ";
    std::cin >> fileName;
    out.open(fileName);
    delete[] fileName;
}

FilePrinter::~FilePrinter()
{
    if (size)
    {
        delete[] array;
        out.close();
    }
}

void FilePrinter::print()
{
    for (int i = 0; i < size; i++)
        out << array[i] << " ";
    out << "\n";
    std::cout << "Wrote!\n";
}
