#include "doublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
    this->head = new ListElement;
}

DoublyLinkedList::~DoublyLinkedList()
{
    ListElement *current = head->next;
    ListElement *previous = head;
    while (current != nullptr)
    {
        delete previous;
        previous = current;
        current = current->next;
    }
    delete previous;
}

void DoublyLinkedList::add(int value)
{
    ListElement *nElement = new ListElement(value, head->next, head);
    head->next = nElement;
    ListElement *next = nElement->next;
    if (next != nullptr)
        next->previous = nElement;
}

bool DoublyLinkedList::remove(int value)
{
    ListElement *current = head->next;
    ListElement *previous = head;
    while (current != nullptr && current->value != value)
    {
        previous = current;
        current = current->next;
    }
    if (current == nullptr)
        return false;
    else
    {
        ListElement *next = current->next;
        previous->next = next;
        if (next != nullptr)
            next->previous = previous;
        delete current;
        return true;
    }
}

void DoublyLinkedList::printList()
{
    ListElement *current = head->next;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int DoublyLinkedList::getFirst()
{
    if (head->next != nullptr)
        return head->next->value;
}

bool DoublyLinkedList::exists(int value)
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

DoublyLinkedList::ListElement::ListElement()
    : value(0), next(nullptr), previous(nullptr)
{}

DoublyLinkedList::ListElement::ListElement(int newValue, DoublyLinkedList::ListElement *newNext,
                                           ListElement *newPrevious)
    : value(newValue), next(newNext), previous(newPrevious)
{}
