#include "sortedSet.h"

SortedSet::SortedSet() : top(new SetElement)
{}

SortedSet::~SortedSet()
{
    SetElement *previous = top;
    SetElement *current = top->next;
    while (current != nullptr)
    {
        delete previous->element;
        delete previous;
        previous = current;
        current = current->next;
    }
    delete previous->element;
    delete previous;
}

void SortedSet::add(Comparable *newElement)
{
    SetElement *previous = top;
    SetElement *current = top->next;
    while (current != nullptr && newElement->compareTo(current->element) > 0)
    {
        previous = current;
        current = current->next;
    }
    previous->next = new SetElement(newElement, current);
}

void SortedSet::print()
{
    SetElement *current = top->next;
    while (current != nullptr)
    {
        current->element->print();
        current = current->next;
    }
}

SortedSet::SetElement::SetElement() : element(nullptr), next(nullptr)
{}

SortedSet::SetElement::SetElement(Comparable *element, SortedSet::SetElement *next)
{
    this->element = element->cloneYourself();
    this->next = next;
}
