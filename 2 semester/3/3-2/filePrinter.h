#pragma once

#include <fstream>
#include <iostream>
#include "printer.h"

/**
 * @brief The FilePrinter class
 * Class inherited from Printer
 * It prints matrix into file
 */

class FilePrinter : public Printer
{
public:
    /// constructors
    FilePrinter();
    FilePrinter(int *newArray, int newSize);

    /// destructor
    ~FilePrinter();

    /// realization of inherited method
    void print();

private:
    int *array;
    int size;
    std::ofstream out;
};
