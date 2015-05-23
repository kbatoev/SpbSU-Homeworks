#pragma once

#include <QString>
#include "treeNode.h"
#include "operandNode.h"
#include "addition.h"
#include "multiplication.h"
#include "subtraction.h"
#include "division.h"

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
    void add(const int &value);

    /// adding operation
    void add(const QChar &action);

    int count();
    void print();

private:

    TreeNode* determineOperation(const QChar &action);
    bool isNumber(const QString &expression, int index);

    int convertNumber(const QString &expression, int &i);
    bool isOperation(const QString &expression, int i);

    void add(TreeNode* &current, const int &value);
    void add(TreeNode* &current, const QChar &action);

    TreeNode *head;
};

