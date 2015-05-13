#pragma once

#include <iostream>

/**
 * SmartPointer class improves effectiveness of cleaning memory.
 * According to RAII
 */

template <typename T>
class SmartPointer
{
public:
    /// counter-linksNumber begins with 1
    SmartPointer(T* element);

    /// increases counter
    SmartPointer(const SmartPointer<T> &elementToCopy);

    /// decreases counter and if it's zero frees memory
    ~SmartPointer() { cleanUsedMemory(); }

    /// it lets use initial object
    T* getOriginPointer();

    /// before assignment frees "old memory"
    SmartPointer<T> & operator = (SmartPointer<T> &that);

    int getNumberOfLinks();

private:

    void cleanUsedMemory();

    T *pointer;
    int *linksNumber;
};

template <typename T>
SmartPointer<T>::SmartPointer(T *element)
{
    linksNumber = new int(1);
    pointer = element;
}

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T> &elementToCopy)
{
    linksNumber = elementToCopy.linksNumber;
    (*linksNumber)++;
    pointer = elementToCopy.pointer;
}

template <typename T>
int SmartPointer<T>::getNumberOfLinks()
{
    return *linksNumber;
}

template <typename T>
void SmartPointer<T>::cleanUsedMemory()
{
    if (linksNumber)
    {
        *linksNumber -= 1;
        if (!*linksNumber)
        {
            delete linksNumber;
            delete[] pointer;
        }
    }
}

template <typename T>
T *SmartPointer<T>::getOriginPointer()
{
    return pointer;
}

template <typename T>
SmartPointer<T> &SmartPointer<T>::operator =(SmartPointer<T> &that)
{
    cleanUsedMemory();
    pointer = that.pointer;
    linksNumber = that.linksNumber;
    (*linksNumber)++;
    return *this;
}
