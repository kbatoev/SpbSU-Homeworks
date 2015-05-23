#pragma once

/**
 * @brief The Comparable class
 * Interface that let you compare something you want to compare
 */

class Comparable
{
public:

    virtual ~Comparable() {}

    /**
     * @brief compareTo. Method that compares this copy with that copy of class
     */
    virtual int compareTo(Comparable *that) = 0;

    virtual int getSize() = 0;

    /**
     * @brief cloneYourself. Method dupliacates this example of class
     */
    virtual Comparable* cloneYourself() = 0;

    /**
     * @brief print. Prints elements of current example
     */
    virtual void print() = 0;

protected:
    enum comparatorResult
    {
        less = -1,
        equal,
        more
    };
};

