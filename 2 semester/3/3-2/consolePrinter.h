#pragma once

#include <iostream>
#include "printer.h"

class ConsolePrinter : Printer
{
public:
    ConsolePrinter();
    ConsolePrinter(int *array, int size);
    ~ConsolePrinter();
    void print();
private:
    int *array;
    int size;
};
