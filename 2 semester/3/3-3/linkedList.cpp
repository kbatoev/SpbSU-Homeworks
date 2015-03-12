#include "linkedList.h"

LinkedList::ListElement::ListElement() : value(0), next(nullptr)
{}

LinkedList::ListElement::ListElement(int newValue, LinkedList::ListElement *newNext)
    : value(newValue), next(newNext)
{}

LinkedList::LinkedList()
{
    size = 0;
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
    size++;
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
        size--;
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

int LinkedList::compareTo(ListsComparator *list)
{
    if (getSizeOfList() < list->getSizeOfList())
        return -1;
    else
    if (getSizeOfList() > list->getSizeOfList())
        return 1;
    else
        return 0;
}

int LinkedList::getSizeOfList()
{
    return size;
}

LinkedList *LinkedList::cloneList()
{
    LinkedList *newList = new LinkedList;
    ListElement *current = head->next;
    while (current != nullptr)
    {
        newList->add(current->value);
        current = current->next;
    }
    return newList;
}
