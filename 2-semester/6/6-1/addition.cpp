#include "addition.h"

int AdditionNode::count()
{
    return leftChild->count() + rightChild->count();
}

void AdditionNode::print()
{
    std::cout << "(";
    leftChild->print();
    std::cout << " + ";
    rightChild->print();
    std::cout << ")";
}
