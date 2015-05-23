#pragma once

#include <iostream>
#include <ostream>

/**
 *  Template class Vector
 */

template <typename T>
class Vector
{
public:

    Vector();
    ~Vector();
    Vector(int newDimension, T *newCoordinates);

    /// copy-constructor
    Vector(const Vector<T> &that);

    /// coordinate-wise operations
    Vector<T> operator +(const Vector<T> &that);
    Vector<T> operator -(const Vector<T> &that);

    /// scalar multiplication
    T operator *(const Vector<T> &that);

    /// comparing of arrays
    bool operator ==(const Vector<T> &that);

    bool isZeroVector();


    friend std::ostream & operator <<(std::ostream &os, Vector<T> &that)
    {
        for (int i = 0; i < that.dimension; i++)
            os << that.coordinates[i] << " ";
        return os;
    }

private:
    int dimension;
    T* coordinates;
};

template <typename T>
Vector<T>::Vector() : dimension(1)
{
    coordinates = new T[1];
    coordinates[0] = 0;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] coordinates;
}

template <typename T>
Vector<T>::Vector(int newDimension, T *newCoordinates)
{
    dimension = newDimension;
    coordinates = new T[dimension];
    for (int i = 0; i < dimension; i++)
        coordinates[i] = newCoordinates[i];
}

template <typename T>
Vector<T>::Vector(const Vector<T> &that)
{
    dimension = that.dimension;
    coordinates = new T[dimension];
    T *newCoordinates = that.coordinates;
    for (int i = 0; i < dimension; i++)
        coordinates[i] = newCoordinates[i];
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &that)
{
    T *newCoordinates = new T[dimension];
    for (int i = 0; i < dimension; i++)
        newCoordinates[i] = coordinates[i] + that.coordinates[i];
    return Vector<T>(dimension, newCoordinates);
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &that)
{
    T *newCoordinates = new T[dimension];
    for (int i = 0; i < dimension; i++)
        newCoordinates[i] = coordinates[i] - that.coordinates[i];
    return Vector<T>(dimension, newCoordinates);
}

template <typename T>
T Vector<T>::operator *(const Vector<T> &that)
{
    T scalarProduct = 0;
    for (int i = 0; i < dimension; i++)
        scalarProduct += coordinates[i] * that.coordinates[i];
    return scalarProduct;
}

template <typename T>
bool Vector<T>::operator ==(const Vector<T> &that)
{
    T *coordinatesToCompare = that.coordinates;
    for (int i = 0; i < dimension; i++)
        if (coordinatesToCompare[i] != coordinates[i])
            return false;
    return true;
}

template <typename T>
bool Vector<T>::isZeroVector()
{
    for (int i = 0; i < dimension; i++)
        if (coordinates[i])
            return false;
    return true;
}
