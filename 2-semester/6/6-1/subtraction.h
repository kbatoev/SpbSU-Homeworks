#pragma once

#include "treeNode.h"

class SubtractionNode : public TreeNode
{
public:

    SubtractionNode() : TreeNode(left) {}
    ~SubtractionNode() {}
    int count();
    void print();
};


