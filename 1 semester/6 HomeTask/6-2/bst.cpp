#include "bst.h"

struct BSTreeNode
{
    int number;
    char operation;
    int direction;
    BSTreeNode *leftChild;
    BSTreeNode *rightChild;
};

struct BSTree
{
    BSTreeNode *root;
};

bool isOperation(char operation)
{
    char operations[4] = {'+', '-', '*', '/'};
    for (int i = 0; i < 4; i++)
        if (operation == operations[i])
            return true;
    return false;
}

BSTreeNode *createBSTreeNode(int number, char operation)
{
    BSTreeNode *node = new BSTreeNode;
    node->number = number;
    node->operation = operation;
    node->leftChild = nullptr;
    node->rightChild = nullptr;

    if (isOperation(operation))
        node->direction = 0;
    else
        node->direction = 2;

    return node;
}

BSTree *createBSTree()
{
    BSTree *tree = new BSTree;
    tree->root = nullptr;
    return tree;
}

void addElement(BSTreeNode* &node, int number, char operation)
{
    if (node == nullptr)
    {
        node = createBSTreeNode(number, operation);
    }
    else
    {
        if (node->direction == 1)
        {
            addElement(node->rightChild, number, operation);
            if (node->rightChild->direction == 2)
                node->direction = 2;
        }
        else
        {
            addElement(node->leftChild, number, operation);
            if (node->leftChild->direction == 2)
                node->direction = 1;
        }
    }
}

void addElement(BSTree *tree, int number, char operation)
{
    addElement(tree->root, number, operation);
}

void printInfix(BSTreeNode *node)
{
    if (node != nullptr)
    {
        if (node->leftChild == nullptr)
            cout << node->number << " ";
        else
        {
            cout << "(";
            printInfix(node->leftChild);
            cout << node->operation << " ";
            printInfix(node->rightChild);
            cout << ") ";
        }
    }
}

void printInfix(BSTree *tree)
{
    printInfix(tree->root);
}

void deleteBSTreeNode(BSTreeNode* &node)
{
    if (node != nullptr)
    {
        deleteBSTreeNode(node->leftChild);
        deleteBSTreeNode(node->rightChild);
        delete node;
        node = nullptr;
    }
}

void deleteBSTree(BSTree *tree)
{
    deleteBSTreeNode(tree->root);
}

enum Operations
{
    addition,
    subtraction,
    multiplication,
    division
};

Operations determineOperation(char operation)
{
    if (operation == '+')
        return addition;
    if (operation == '-')
        return subtraction;
    if (operation == '*')
        return multiplication;
    if (operation == '/')
        return division;
}

void add(BSTreeNode* &node)
{
    BSTreeNode *leftChild = node->leftChild;
    BSTreeNode *rightChild = node->rightChild;
    node->number = leftChild->number + rightChild->number;
}

void subtract(BSTreeNode* &node)
{
    BSTreeNode *leftChild = node->leftChild;
    BSTreeNode *rightChild = node->rightChild;
    node->number = leftChild->number - rightChild->number;
}

void multiply(BSTreeNode* &node)
{
    BSTreeNode *leftChild = node->leftChild;
    BSTreeNode *rightChild = node->rightChild;
    node->number = leftChild->number * rightChild->number;
}

void divide(BSTreeNode* &node)
{
    BSTreeNode *leftChild = node->leftChild;
    BSTreeNode *rightChild = node->rightChild;
    node->number = leftChild->number / rightChild->number;
}

void countExpression(BSTreeNode *node)
{
    if (node != nullptr)
    {
        countExpression(node->leftChild);
        countExpression(node->rightChild);
        if (isOperation(node->operation))
        {
            Operations action = determineOperation(node->operation);
            switch (action)
            {
            case addition:
                add(node); break;
            case subtraction:
                subtract(node); break;
            case multiplication:
                multiply(node); break;
            case division:
                divide(node); break;
            }
        }
    }
}

int countExpression(BSTree *tree)
{
    countExpression(tree->root);
    return tree->root->number;
}
