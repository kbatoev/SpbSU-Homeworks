#pragma once

#include "stack.h"

class ArrayStack : Stack
{
public:
    ArrayStack();
    ~ArrayStack();
    void push(const int &value);
    int top();
    void pop();
    bool isEmpty();

private:
    int index;
    int *array;
    int maxSize;
};

