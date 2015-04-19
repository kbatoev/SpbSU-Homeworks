#pragma once

#include <iostream>
#include "treeNode.h"

class OperandNode : public TreeNode
{
public:
    OperandNode(int value);
    ~OperandNode();
    int count();
    void print();

private:
    int operand;
};

