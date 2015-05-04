#include "linkedStack.h"

LinkedStack::LinkedStack() : head(new StackElement)
{}

LinkedStack::~LinkedStack()
{
    StackElement *previous = head;
    StackElement *current = head->next;
    while (current != nullptr)
    {
        delete previous;
        previous = current;
        current = current->next;
    }
    delete previous;
}

void LinkedStack::push(double value)
{
    head->next = new StackElement(value, head->next);
}

double LinkedStack::top()
{
    if (!isEmpty())
        return head->next->value;
    else
        return 0;
}

void LinkedStack::pop()
{
    if (!isEmpty())
    {
        StackElement *current = head->next;
        head->next = current->next;
        delete current;
    }
}

bool LinkedStack::isEmpty()
{
    return head->next == nullptr;
}

LinkedStack::StackElement::StackElement() : value(0), next(nullptr)
{}

LinkedStack::StackElement::StackElement(double newValue, LinkedStack::StackElement *newNext)
    : value(newValue), next(newNext)
{}
