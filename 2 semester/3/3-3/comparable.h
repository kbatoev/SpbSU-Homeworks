#pragma once

/**
 * @brief The Comparable class
 * Interface that let you compare something you want to compare
 */

class Comparable
{
public:

    /**
     * @brief ~Comparable
     */
    virtual ~Comparable() {}

    /**
     * @brief compareTo. Method that compares this copy with that copy of class
     * @param that
     */
    virtual int compareTo(Comparable *that) = 0;

    /**
     * @brief getSize
     * @return size of current copy of class
     */
    virtual int getSize() = 0;

    /**
     * @brief cloneYourself. Method dupliacates this example of class
     * @return
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

