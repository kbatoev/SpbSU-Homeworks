#pragma once

#include "treeNode.h"

class DivisionNode : public TreeNode
{
public:
    DivisionNode() : TreeNode(left) {}
    ~DivisionNode() {}
    int count();
    void print();
};

