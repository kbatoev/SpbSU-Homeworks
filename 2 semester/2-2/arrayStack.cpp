#include "arrayStack.h"

ArrayStack::ArrayStack()
{
    index = 0;
    maxSize = 1000;
    array = new int[maxSize];
}

ArrayStack::~ArrayStack()
{
    delete[] array;
}

void ArrayStack::push(int value)
{
    if (index == maxSize)
    {
        maxSize *= 2;
        int *newArray = new int[maxSize];
        for (int i = 0; i < maxSize; i++)
            newArray[i] = array[i];
        delete array;
        array = newArray;
    }
    array[index++] = value;
}

int ArrayStack::top()
{
    if (index)
        return array[index - 1];
    else
        return 0;
}

void ArrayStack::pop()
{
    if (index)
        index--;
}

bool ArrayStack::isEmpty()
{
    return index == 0;
}
