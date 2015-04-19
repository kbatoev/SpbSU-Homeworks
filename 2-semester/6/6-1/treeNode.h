#pragma once

class TreeNode
{
public:
    virtual ~TreeNode() {}
    virtual int count() = 0;
    virtual void print() = 0;

    enum Direction
    {
        left,
        right,
        noWay
    };

    Direction way;
    TreeNode *leftChild;
    TreeNode *rightChild;
};

