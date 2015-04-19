#include "operandNode.h"

OperandNode::OperandNode(int value)
{
    operand = value;
    way = noWay;
    leftChild = nullptr;
    rightChild = nullptr;
}

OperandNode::~OperandNode()
{}

int OperandNode::count()
{
    return operand;
}

void OperandNode::print()
{
    std::cout << operand;
}

