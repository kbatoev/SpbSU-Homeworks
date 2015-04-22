#pragma once

#include <QString>
#include "treeNode.h"
#include "operandNode.h"
#include "operatorNode.h"

/**
 * @brief The Tree class
 */

class Tree
{
public:
    Tree();

    /// creation of tree using inputted expression
    Tree(const QString &expression);
    ~Tree();

    /// adding number
    void add(int value);

    /// adding operation
    void add(QChar action);

    int count();
    void print();

private:
    bool isNumber(const QString &expression, int index);

    int convertNumber(const QString &expression, int &i);
    bool isOperation(const QString &expression, int i);

    void add(TreeNode* &current, int value);
    void add(TreeNode* &current, QChar action);

    TreeNode *head;
};

