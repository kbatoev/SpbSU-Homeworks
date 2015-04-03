#pragma once

/**
 * @brief The LinkedStack class
 */

class LinkedStack
{
public:
    /// constructor
    LinkedStack();

    /// destructor
    ~LinkedStack();

    /**
     * @brief push - creates new StackElement
     * @param value - new StackElement's value
     */
    void push(double value);

    /**
     * @brief top
     * @return value of top-element in Stack
     */
    double top();

    /**
     * @brief pop - deletes top StackElement
     */
    void pop();

    /**
     * @brief isEmpty - checks if Stack is empty
     * @return
     */
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
