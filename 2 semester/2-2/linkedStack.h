#pragma once

#include "stack.h"

class LinkedStack : Stack
{
private:
    class StackElement
    {
    public:
        int value;
        StackElement *next;
        StackElement();
        StackElement(int value, StackElement *next);
    };
    StackElement *head;

public:
    LinkedStack();
    ~LinkedStack();
    void push(int value);
    int top();
    void pop();
    bool isEmpty();
};
