#pragma once

#include <string>
#include <iostream>

class MoveToFront
{
public:
    MoveToFront(std::string newString)
    {
        line = newString;
        array = new int[line.size()];
    }
    ~MoveToFront();
    int *getResult();
    void transform();
    void print();

private:
    std::string line;
    int *array;
    const int numberOfLettersInEnglish = 26;
};

