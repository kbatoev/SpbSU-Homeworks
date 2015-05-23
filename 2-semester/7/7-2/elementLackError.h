#pragma once
#include <iostream>
#include <string>

class ElementLackError
{
public:
    ElementLackError() : comment("You try to delete nonexistent element!")
    {}
    ElementLackError(std::string message) : comment(message)
    {}
    ~ElementLackError()
    {}

    void print()
    {
        std::cout << comment << "\n";
    }

private:
    std::string comment;
};
