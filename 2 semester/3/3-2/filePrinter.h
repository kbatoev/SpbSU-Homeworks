#pragma once

#include <fstream>
#include <iostream>
#include "printer.h"

class FilePrinter : public Printer
{
public:
    FilePrinter();
    FilePrinter(int *newArray, int newSize);
    ~FilePrinter();
    void print();

private:
    int *array;
    int size;
    std::ofstream out;
};
