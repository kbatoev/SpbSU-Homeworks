#pragma once

#include <iostream>
#include "printer.h"

/**
 * @brief The ConsolePrinter class
 * Class inherited from Printer
 * It prints matrix onto console
 */

class ConsolePrinter : public Printer
{
public:

    /// constructors
    ConsolePrinter();
    ConsolePrinter(int *newArray, int newSize);

    /// destructor
    ~ConsolePrinter();

    /// realization of inherited method
    void print();

private:
    int *array;
    int size;
};

