#include "operandNode.h"

OperandNode::OperandNode(int value) : TreeNode(), operand(value)
{}

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

