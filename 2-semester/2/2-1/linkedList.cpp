#include "linkedList.h"

LinkedList::ListElement::ListElement() : value(0), next(nullptr)
{}

LinkedList::ListElement::ListElement(int newValue, LinkedList::ListElement *newNext)
    : value(newValue), next(newNext)
{}

LinkedList::LinkedList()
{
    head = new ListElement;
}

LinkedList::~LinkedList()
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

void LinkedList::add(int value)
{
    ListElement *newElement = new ListElement(value, head->next);
    head->next = newElement;
}

bool LinkedList::remove(int value)
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

void LinkedList::printList()
{
    ListElement *current = head->next;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
}

int LinkedList::getFirst()
{
    if (head->next != nullptr)
        return head->next->value;
}

bool LinkedList::exists(int value)
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
