#pragma once

#include "stack.h"

class ArrayStack : Stack
{
private:
    int index;
    int *array;
    int maxSize;
public:
    ArrayStack();
    ~ArrayStack();
    void push(int value);
    int top();
    void pop();
    bool isEmpty();
};

