#include "arrayStack.h"

ArrayStack::ArrayStack()
{
    index = 0;
    size = 1000;
    array = new int[size];
}

ArrayStack::~ArrayStack()
{
    delete[] array;
}

void ArrayStack::push(int value)
{
    if (index == size)
    {
        size *= 2;
        int *newArray = new int[size];
        for (int i = 0; i < size; i++)
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





