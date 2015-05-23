#pragma once

#include "treeNode.h"

class AdditionNode : public TreeNode
{
public:
    AdditionNode() : TreeNode(left) {}
    ~AdditionNode() {}
    int count();
    void print();
};
