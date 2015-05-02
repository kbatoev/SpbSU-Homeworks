#pragma once

#include "repetitionError.h"
#include "elementLackError.h"

/**
 * Template class - UniqueList.
 * It's common list, but supports exceptions.
 * They can occur by adding existent element
 * and by removing nonexistent one.
 */

template <typename T>
class UniqueList
{
public:
    UniqueList();
    ~UniqueList();
    void add(T value);
    void remove(T value);
    void printList();

private:
    bool exists(T value);

    class ListElement
    {
    public:
        T value;
        ListElement *next;
        ListElement();
        ListElement(T newValue, ListElement *newNext);
    };
    ListElement *head;
};

template <typename T>
UniqueList<T>::ListElement::ListElement() : next(nullptr)
{}


template <typename T>
UniqueList<T>::ListElement::ListElement(T newValue, ListElement *newNext)
    : value(newValue), next(newNext)
{}

template <typename T>
UniqueList<T>::UniqueList()
{
    head = new ListElement;
}

template <typename T>
UniqueList<T>::~UniqueList()
{
    ListElement *current = head->next;
    ListElement *previous = head;
    while (current != nullptr)
    {
        delete previous;
        previous = current;
        current = current->next;
    }
}

template <typename T>
void UniqueList<T>::add(T value)
{
    if (exists(value))
        throw RepetitionError("There is such element");

    ListElement *newElement = new ListElement(value, head->next);
    head->next = newElement;
}

template <typename T>
void UniqueList<T>::remove(T value)
{
    ListElement *previous = head;
    ListElement *current = head->next;
    while (current != nullptr && current->value != value)
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr)
        throw ElementLackError();
    else
    {
        previous->next = current->next;
        delete current;
    }
}

template <typename T>
bool UniqueList<T>::exists(T value)
{
    ListElement *current = head->next;
    while (current != nullptr)
    {
        if (current->value == value)
            return true;
        current = current->next;
    }
    return false;
}

template <typename T>
void UniqueList<T>::printList()
{
    ListElement *current = head->next;
        while (current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->next;
        }
}
