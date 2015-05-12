#pragma once

#include <iostream>

template <typename T>
class SmartPointer
{
public:
    SmartPointer();
    SmartPointer(T *element);
    SmartPointer(const SmartPointer &elementToCopy);

    ~SmartPointer();

    T& operator * ()
    {
        return *pointer;
    }

    SmartPointer& operator = (SmartPointer &that)
    {
        pointer = that.pointer;
        pointerNumber = that.pointerNumber;
        (*pointerNumber)++;
        return *this;
    }

    void showNumber();

private:
    T *pointer;
    int *pointerNumber;
};

template <typename T>
SmartPointer<T>::SmartPointer()
{}

template <typename T>
SmartPointer<T>::SmartPointer(T *element)
{
    pointerNumber = new int(1);
    pointer = element;
}

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer &elementToCopy)
{
    pointerNumber = elementToCopy.pointerNumber;
    (*pointerNumber)++;
    pointer = elementToCopy.pointer;
}

template <typename T>
SmartPointer<T>::~SmartPointer()
{
    (*pointerNumber)--;
    if (!(*pointerNumber))
    {
        delete pointerNumber;
        delete pointer;
    }
}

template <typename T>
void SmartPointer<T>::showNumber()
{
    std::cout << "Links number is " << *pointerNumber << "\n";
}
