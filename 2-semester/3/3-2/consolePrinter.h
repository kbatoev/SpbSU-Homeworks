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

    ConsolePrinter();
    ConsolePrinter(int *newArray, int newSize);
    ~ConsolePrinter();

    /// realization of inherited method
    void print();

private:
    int *array;
    int size;
};

