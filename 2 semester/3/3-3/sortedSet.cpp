#include "sortedSet.h"

SortedSet::SetElement::SetElement()
{
    list = nullptr;
    next = nullptr;
}

SortedSet::SetElement::SetElement(LinkedList *newList, SortedSet::SetElement *nextElement)
{
    list = newList;
    next = nextElement;
}

SortedSet::SortedSet()
{
    sizeOfSet = 0;
    head = new SetElement;
}

SortedSet::~SortedSet()
{
    SetElement *previous = head;
    SetElement *current = head->next;
    while (current != nullptr)
    {
        delete previous;
        previous = current;
        current = current->next;
    }
    delete previous;
}

int SortedSet::getSizeOfSet()
{
    return sizeOfSet;
}

void SortedSet::addList(LinkedList *newList)
{
    sizeOfSet++;
    LinkedList *copy = newList->cloneList();
    SetElement *previous = head;
    SetElement *current = head->next;
    while (current != nullptr && newList->compareTo(current->list) > 0)
    {
        previous = current;
        current = current->next;
    }
    previous->next = new SetElement(copy, current);
}

void SortedSet::printSet()
{
    std::cout << "There're " << sizeOfSet << " lists.\n";
    SetElement *current = head->next;
    for (int i = 0; i < sizeOfSet; i++)
    {
        std::cout << "The " << i + 1 << " list contains:\n";
        current->list->printList();
        std::cout << "\n";
        current = current->next;
    }
}



