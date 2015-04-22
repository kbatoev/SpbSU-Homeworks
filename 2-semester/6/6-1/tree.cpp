#include "tree.h"

Tree::Tree()
{
    head = nullptr;
}

bool Tree::isNumber(const QString &expression, int i)
{
    return (expression[i].isDigit() || i < expression.size() - 1 && expression[i] == (QChar)'-'
            && expression[i + 1].isDigit());
}

int Tree::convertNumber(const QString &expression, int &i)
{
    QString number = "";
    if (expression[i].isDigit())
    {
        while (expression[i].isDigit())
            number += expression[i++];
    }
    else
        if (i < expression.size() - 1 && expression[i] == (QChar)'-'
                && expression[i + 1].isDigit())
        {
            number += expression[i++];
            while (expression[i].isDigit())
                number += expression[i++];
        }
    return number.toInt();
}

bool Tree::isOperation(const QString &expression, int i)
{
    const QChar operations[4] = {'+', '-', '*', '/'};
    for (int j = 0; j < 4; j++)
        if (expression[i] == operations[j])
            return true;
    return false;
}

Tree::Tree(const QString &expression)
{
    head = nullptr;
    int i = 0;
    while (i < expression.size())
    {
        if (isNumber(expression, i))
            add(convertNumber(expression, i));
        if (isOperation(expression, i))
            add(expression[i]);
        i++;
    }

}

Tree::~Tree()
{
    delete head;
}

void Tree::add(int value)
{
    add(head, value);
}

void Tree::add(TreeNode* &current, int value)
{
    if (current == nullptr)
        current = new OperandNode(value);
    else
    {
        if (current->way == TreeNode::Direction::left)
        {
            add(current->leftChild, value);
            if (current->leftChild->way ==  TreeNode::Direction::noWay)
                current->way = TreeNode::Direction::right;
        }
        else
            if (current->way == TreeNode::Direction::right)
            {
                add(current->rightChild, value);
                if (current->rightChild->way == TreeNode::Direction::noWay)
                    current->way = TreeNode::Direction::noWay;
            }

    }
}

void Tree::add(QChar action)
{
    add(head, action);
}

int Tree::count()
{
    if (head != nullptr)
        return head->count();
}

void Tree::print()
{
    head->print();
    std::cout << "\n";
}

void Tree::add(TreeNode *&current, QChar action)
{
    if (current == nullptr)
        current = new OperatorNode(action);
    else
    {
        if (current->way == TreeNode::Direction::left)
            add(current->leftChild, action);
        else
            if (current->way == TreeNode::Direction::right)
                add(current->rightChild, action);
            else
                std::cout << "WRONG INPUT!\n";
    }
}
