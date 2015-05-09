#pragma once

#include "treeNode.h"

class MultiplicationNode : public TreeNode
{
public:
    MultiplicationNode() : TreeNode(left) {}
    ~MultiplicationNode() {}
    int count();
    void print();
};

