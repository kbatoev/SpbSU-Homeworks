#pragma once

#include "stack.h"

class ArrayStack : Stack
{
public:
    ArrayStack();
    ~ArrayStack();
    void push(int value);
    int top();
    void pop();
    bool isEmpty();

private:
    int index;
    int *array;
    int maxSize;
};

