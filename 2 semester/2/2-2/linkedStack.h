#pragma once

#include "stack.h"

class LinkedStack : Stack
{
public:
    LinkedStack();
    ~LinkedStack();
    void push(int value);
    int top();
    void pop();
    bool isEmpty();

private:
    class StackElement
    {
    public:
        int value;
        StackElement *next;
        StackElement();
        StackElement(int newValue, StackElement *newNext);
    };
    StackElement *head;
};