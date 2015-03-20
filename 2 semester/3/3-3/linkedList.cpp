#include "linkedList.h"

LinkedList::ListElement::ListElement() : value(0), next(nullptr)
{}

LinkedList::ListElement::ListElement(int value, LinkedList::ListElement *next)
{
    this->value = value;
    this->next = next;
}

LinkedList::LinkedList()
{
    size = 0;
    head = new ListElement;
}

LinkedList::~LinkedList()
{
    ListElement *previous = head;
    ListElement *current = head->next;
    while (current != nullptr)
    {
        delete previous;
        previous = current;
        current = current->next;
    }
    delete previous;
}

void LinkedList::add(int number)
{
    head->next = new ListElement(number, head->next);
    size++;
}

bool LinkedList::remove(int number)
{
    ListElement *previous = head;
    ListElement *current = head->next;
    while (current != nullptr && current->value != number)
    {
        previous = current;
        current = current->next;
    }
    if (current != nullptr)
    {
        previous->next = current->next;
        delete current;
        size--;
        return true;
    }
    else
        return false;
}

void LinkedList::print()
{
    ListElement *current = head->next;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << "\n";
}

LinkedList *LinkedList::cloneYourself()
{
    LinkedList *nList = new LinkedList;
    ListElement *current = head->next;
    while (current != nullptr)
    {
        nList->add(current->value);
        current = current->next;
    }
    return nList;
}

int LinkedList::compareTo(Comparable *that)
{
    if (this->getSize() < that->getSize())
        return -1;
    if (this->getSize() > that->getSize())
        return 1;
    return 0;
}

int LinkedList::getSize()
{
    return size;
}

