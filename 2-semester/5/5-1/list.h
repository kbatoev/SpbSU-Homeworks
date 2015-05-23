#pragma once

#include <QString>
#include <iostream>

/**
 * Template of LinkedList.
 * Added some functions related to QString.
 */

template <typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    /// standard functions
    void add(const T &value);
    bool remove(const T &value);
    void printList();

    /// added function special for hashTable
    bool find(const T &value);

    /// functions for statistics
    int getSize();
    int getCollisionsNumber();

    /// functions for refreshing hashTable
    T getFirstElement();

private:

    /// compare 2 strings
    static bool areEqual(QString first, QString second);

    class ListElement
    {
    public:
        ListElement();
        ListElement(T newValue, ListElement *newNext);
        T value;
        ListElement *next;
        int countOfThisElement;
    };
    ListElement *head;
    int numberOfAddedWords;
    int numberOfDifferrentWords;
};

template <typename T>
LinkedList<T>::ListElement::ListElement() : next(nullptr), countOfThisElement(0)
{}


template <typename T>
LinkedList<T>::ListElement::ListElement(T newValue, ListElement *newNext)
    : value(newValue), next(newNext), countOfThisElement(1)
{}

template <typename T>
LinkedList<T>::LinkedList() : head(new ListElement), numberOfAddedWords(0),
    numberOfDifferrentWords(0)
{}

template <typename T>
LinkedList<T>::~LinkedList()
{
    ListElement *current = head;
    while (current != nullptr)
    {
        ListElement *toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

template <typename T>
void LinkedList<T>::add(const T &value)
{
    numberOfAddedWords++;
    ListElement *current = head->next;

    while (current != nullptr)
    {
        if (areEqual(value, current->value))
        {
            current->countOfThisElement++;
            return;
        }
        current = current->next;
    }

    ListElement *newElement = new ListElement(value, head->next);
    head->next = newElement;
    numberOfDifferrentWords++;
}

template <typename T>
bool LinkedList<T>::remove(const T &value)
{
    ListElement *previous = head;
    ListElement *current = head->next;
    while (current != nullptr && current->value != value)
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr)
        return false;
    else
    {
        if (current->countOfThisElement > 1)
            current->countOfThisElement--;
        else
        {
            numberOfDifferrentWords--;
            previous->next = current->next;
            delete current;
        }
        numberOfAddedWords--;
        return true;
    }
}

template <typename T>
bool LinkedList<T>::find(const T &value)
{
    ListElement *current = head->next;
    while (current != nullptr)
    {
        if (areEqual(value, current->value))
            return true;
        current = current->next;
    }
    return false;
}

template <typename T>
void LinkedList<T>::printList()
{
    ListElement *current = head->next;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
}

template <typename T>
int LinkedList<T>::getSize()
{
    return numberOfAddedWords;
}

template <typename T>
int LinkedList<T>::getCollisionsNumber()
{
    return numberOfDifferrentWords;
}

template <typename T>
T LinkedList<T>::getFirstElement()
{
    ListElement *current = head->next;
    if (current != nullptr)
        return current->value;
}

template <typename T>
bool LinkedList<T>::areEqual(QString first, QString second)
{
    return !first.compare(second);
}
