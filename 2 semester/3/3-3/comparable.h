#pragma once

class Comparable
{
public:
    virtual ~Comparable() {}
    virtual int compareTo(Comparable *that) = 0;
    virtual int getSize() = 0;
    virtual Comparable* cloneYourself() = 0;
    virtual void print() = 0;
};

