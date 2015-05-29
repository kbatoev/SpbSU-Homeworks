#pragma once

#include <string>
#include <iostream>

class MoveToFront
{
public:
    MoveToFront(std::string newString)
    {
        line = newString;
        arraySize = line.size();
        array = new int[arraySize];
    }
    ~MoveToFront();
    int *getResult();
    void transform();
    void print();

private:
    const int numberOfLettersInEnglish = 26;
    int arraySize;
    std::string line;
    int *array;
};

