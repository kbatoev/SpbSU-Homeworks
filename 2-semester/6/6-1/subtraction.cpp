#include "subtraction.h"

int SubtractionNode::count()
{
    return leftChild->count() - rightChild->count();
}

void SubtractionNode::print()
{
    std::cout << "(";
    leftChild->print();
    std::cout << " - ";
    rightChild->print();
    std::cout << ")";
}
