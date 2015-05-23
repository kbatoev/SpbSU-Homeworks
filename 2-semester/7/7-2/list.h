#pragma once

template <typename T>
class List
{
public:
    virtual ~List() {}
    virtual void add(const T &value) = 0;
    virtual void remove(const T &value) = 0;
    virtual bool exists(const T &value) = 0;
    virtual void printList() = 0;
    virtual int getSize() const = 0;
protected:
    int size;
};
