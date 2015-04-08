#pragma once

template <typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void add(T value);
    bool remove(T value);
    void printList();

private:
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
LinkedList<T>::ListElement::ListElement() : next(nullptr)
{}


template <typename T>
LinkedList<T>::ListElement::ListElement(T newValue, ListElement *newNext)
    : value(newValue), next(newNext)
{}

template <typename T>
LinkedList<T>::LinkedList()
{
    head = new ListElement;
}

template <typename T>
LinkedList<T>::~LinkedList()
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
void LinkedList<T>::add(T value)
{
    ListElement *newElement = new ListElement(value, head->next);
    head->next = newElement;
}

template <typename T>
bool LinkedList<T>::remove(T value)
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
        previous->next = current->next;
        delete current;
        return true;
    }
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
