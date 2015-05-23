#include "division.h"

int DivisionNode::count()
{
    return leftChild->count() / rightChild->count();
}

void DivisionNode::print()
{
    std::cout << "(";
    leftChild->print();
    std::cout << " / ";
    rightChild->print();
    std::cout << ")";
}
