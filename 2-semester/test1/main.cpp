#include <iostream>
#include <string>
#include "movetofront.h"

int main()
{
    std::string line;
    std::cout << "Enter string: \n";
    std::cin >> line;
    MoveToFront alg(line);
    alg.transform();

    std::cout << "String after converting:\n";
    alg.print();


    return 0;
}
