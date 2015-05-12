#include <iostream>
#include "smartPointer.h"

int main()
{

    int a = 90;

    SmartPointer<int> point(new int(15));

    for (int i = 0; i < 10; i++)
        SmartPointer<int> anotherPointer(point);

    SmartPointer<int> anotherPointer;
    anotherPointer = point;

    point.showNumber();

    a = *point;
    std::cout << "a = " << a << "\n";

    return 0;
}
