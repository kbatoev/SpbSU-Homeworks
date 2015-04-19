#pragma once

#include <QString>
#include "treeNode.h"
#include "operandNode.h"
#include "operatorNode.h"

class Tree
{
public:
    Tree();
    Tree(const QString &expression);
    ~Tree();
    void add(int value);
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

