#pragma once

#include <iostream>
#include <fstream>
#include "printer.h"

class FilePrinter : Printer
{
public:
    FilePrinter();
    FilePrinter(int *newArray, int newSize);
    ~FilePrinter();
    void print();

private:
    int *array;
    int size;
};

