#pragma once

#include <iostream>
#include <QString>
#include "treeNode.h"

/**
 * @brief The OperatorNode class
 */

class OperatorNode : public TreeNode
{
public:

    OperatorNode();
    OperatorNode(QChar symbol);
    ~OperatorNode();
    int count();
    void print();

    enum Operations
    {
        addition = 0,
        subtraction,
        multiplication,
        division,
        none
    };

    /// arrays for finding equivalence between 'QChar' and 'Operations'
    QChar charOperations[4] = {'+', '-', '*', '/'};
    Operations operationList[4] = {addition, subtraction, multiplication, division};

private:

    Operations operation;
    QChar transformToQChar();
    int countOperator(int operand1, int operand2);
};

