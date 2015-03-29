#pragma once

/**
 * @brief The Printer class
 */

class Printer
{
public:
    /// virtual destructor
    virtual ~Printer() {}

    /// method print
    virtual void print() = 0;
};

