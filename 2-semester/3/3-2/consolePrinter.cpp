#include "consolePrinter.h"

ConsolePrinter::ConsolePrinter() : size(0), array(nullptr)
{}

ConsolePrinter::ConsolePrinter(int *newArray, int newSize)
{
    size = newSize;
    array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = newArray[i];
}

ConsolePrinter::~ConsolePrinter()
{
    if (size)
        delete[] array;
}

void ConsolePrinter::print()
{
    std::cout << "Array is: \n";
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}
