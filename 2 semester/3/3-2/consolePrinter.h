#pragma once

#include <iostream>
#include "printer.h"

class ConsolePrinter : public Printer
{
public:
    ConsolePrinter();
    ConsolePrinter(int *newArray, int newSize);
    ~ConsolePrinter();
    void print();

private:
    int *array;
    int size;
};

