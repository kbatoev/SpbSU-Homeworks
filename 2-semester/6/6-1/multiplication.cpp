#include "multiplication.h"

int MultiplicationNode::count()
{
    return leftChild->count() * rightChild->count();
}

void MultiplicationNode::print()
{
    std::cout << "(";
    leftChild->print();
    std::cout << " * ";
    rightChild->print();
    std::cout << ")";
}
