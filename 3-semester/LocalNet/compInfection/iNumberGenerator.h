#pragma once

class INumberGenerator
{
public:
    //INumberGenerator(INumberGenerator *currentGenerator);
    virtual int generateNumber() = 0;
};
