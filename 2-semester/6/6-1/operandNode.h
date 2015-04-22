#pragma once

#include <iostream>
#include "treeNode.h"

/**
 * @brief The OperandNode class
 */

class OperandNode : public TreeNode
{
public:
    /// creates a node with no descendant
    OperandNode(int value);
    ~OperandNode();

    /// returns a value
    int count();
    void print();

private:
    int operand;
};

