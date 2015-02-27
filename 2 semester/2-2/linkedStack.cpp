#include "linkedStack.h"

LinkedStack::LinkedStack()
{
    head = new StackElement;
}

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

void LinkedStack::push(int value)
{
    head->next = new StackElement(value, head->next);
}

int LinkedStack::top()
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

LinkedStack::StackElement::StackElement()
{
    next = nullptr;
    value = 0;
}

LinkedStack::StackElement::StackElement(int value, LinkedStack::StackElement *next)
{
    this->value = value;
    this->next = next;
}
