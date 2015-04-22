#pragma once

/**
 * @brief The TreeNode class - virtual class, it's used in Tree Class
 */

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

    /// shows which descendant is available
    Direction way;

    TreeNode *leftChild;
    TreeNode *rightChild;
};

