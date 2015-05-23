#pragma once

#include <iostream>
#include <string.h>

class RepetitionError
{
public:
    RepetitionError() : comment("Error! Such element already exists !\n")
    {}
    RepetitionError(std::string message) : comment(message)
    {}

    ~RepetitionError()
    {}

    void print()
    {
        std::cout << comment << "\n";
    }

private:
  std::string comment;
};

