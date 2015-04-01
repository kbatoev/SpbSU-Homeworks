#pragma once

class LinkedStack
{
public:
    LinkedStack();
    ~LinkedStack();
    void push(double value);
    double top();
    void pop();
    bool isEmpty();

private:
    class StackElement
    {
    public:
        StackElement();
        StackElement(double newValue, StackElement *newNext);
        double value;
        StackElement *next;
    };
    StackElement *head;
};
