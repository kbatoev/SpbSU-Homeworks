#pragma once

#include "linkedList.h"
#include "repetitionError.h"
#include "elementLackError.h"

/**
 * Template class - UniqueList inherited from LinkedList
 * It's common list, but supports exceptions.
 * They can occur by adding existent element
 * and by removing nonexistent one.
 */

template <typename T>
class UniqueList : public LinkedList<T>
{
public:
    void add(const T &value);
    void remove(const T &value);
};

template <typename T>
void UniqueList<T>::add(const T &value)
{
    if (LinkedList<T>::exists(value))
        throw RepetitionError("There is such element");

    LinkedList<T>::add(value);
}

template <typename T>
void UniqueList<T>::remove(const T &value)
{
    if (!this->exists(value))
        throw ElementLackError();
    else
        this->LinkedList<T>::remove(value);
}
