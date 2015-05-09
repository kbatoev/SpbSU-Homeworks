#pragma once

#include "list.h"
#include <iostream>

template <typename T>
class LinkedList : public List<T>
{
public:
    LinkedList();
    ~LinkedList();
    void add(const T &value);
    void remove(const T &value);
    bool exists(const T &value);
    void printList();
    int getSize() const;

protected:
    class ListElement
    {
    public:
        T value;
        ListElement *next;
        ListElement() : next(nullptr)
        {}
        ListElement(T newValue, ListElement *newNext) : value(newValue), next(newNext)
        {}
    };
    ListElement *head;
};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = new ListElement;
    this->size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    ListElement *current = head;
    while (current)
    {
        ListElement *next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::add(const T &value)
{
    head->next = new ListElement(value, head->next);
    this->size++;
}

template <typename T>
void LinkedList<T>::remove(const T &value)
{
    ListElement *previous = head;
    ListElement *current = head->next;
    while (current != nullptr && current->value != value)
    {
        previous = current;
        current = current->next;
    }

    if (current)
    {
        previous->next = current->next;
        delete current;
        this->size--;
    }
}

template <typename T>
bool LinkedList<T>::exists(const T &value)
{
    ListElement *current = head;
    while (current != nullptr)
    {
        if (current->value == value)
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
int LinkedList<T>::getSize() const
{
    return this->size;
}
