#include <iostream>

class DynamicArray
{
public:
    DynamicArray() : array(nullptr)
    {
        try
        {
            //throw 45;
            array = new int[100];
            //throw 123;
        }
        catch(...)
        {
            if (array != nullptr)
                delete[] array;
            std::cout << "Memory was cleared because of exception\n";
            throw;
        }
    }

    ~DynamicArray()
    {
        if (array != nullptr)
            delete[] array;
        std::cout << "Memory is free...\n";
    }

private:
    int *array;
};


class Wrapper
{
public:
    Wrapper()
    {
        throw "exception";
    }

    ~Wrapper() {}

private:
    DynamicArray stackArray;
};


int main()
{
    try
    {
        DynamicArray sample; // OK
        //DynamicArray *sample = new DynamicArray; // память не освободится
        throw 90;
    }

    catch(int &error)
    {
        std::cout << "Exception's code is: " << error << "\n";
    }

    std::cout << "\n\n";

    try
    {
        Wrapper test;
    }

    catch(...)
    {
        std::cout << "Something bad happened :(\nBut memory is ok\n";
    }

    return 0;
}
