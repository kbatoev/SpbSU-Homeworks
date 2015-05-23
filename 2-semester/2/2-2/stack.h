#pragma once

class Stack
{
public:
    virtual ~Stack() {}
    virtual int top() = 0;
    virtual void pop() = 0;
    virtual void push(const int &value) = 0;
    virtual bool isEmpty() = 0;
};

