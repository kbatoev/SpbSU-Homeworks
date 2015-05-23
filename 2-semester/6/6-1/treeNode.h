#pragma once

#include <iostream>

/**
 * @brief The TreeNode class - virtual class, it's used in Tree Class
 */

class TreeNode
{
public:

    enum Direction
    {
        left,
        right,
        noWay
    };

    TreeNode() : way(noWay), leftChild(nullptr), rightChild(nullptr)
    {}
    TreeNode(Direction currentWay) : way(currentWay), leftChild(nullptr), rightChild(nullptr)
    {}

    virtual ~TreeNode() {}
    virtual int count() = 0;
    virtual void print() = 0;

    /// shows which descendant is available
    Direction way;

    TreeNode *leftChild;
    TreeNode *rightChild;
};

