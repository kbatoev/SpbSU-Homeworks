#pragma once

template <typename T>
class List
{
public:
    virtual ~List() {}
    virtual void add(T value) = 0;
    virtual void remove(T value) = 0;
    virtual bool exists(T value) = 0;
    virtual void printList() = 0;
    virtual int getSize() const = 0;
protected:
    int size;
};
