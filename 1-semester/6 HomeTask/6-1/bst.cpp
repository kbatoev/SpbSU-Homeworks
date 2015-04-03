#include "bst.h"

struct BSTreeNode
{
    int value;
    BSTreeNode *leftChild;
    BSTreeNode *rightChild;
};

struct BSTree
{
    BSTreeNode *root;
};

BSTreeNode *createBSTreeNode(int value)
{
    BSTreeNode *node = new BSTreeNode;
    node->value = value;
    node->leftChild = nullptr;
    node->rightChild = nullptr;
    return node;
}

BSTree *createBSTree()
{
    BSTree *tree = new BSTree;
    tree->root = nullptr;
    return tree;
}

void addElement(BSTreeNode* &node, int value)
{
    if (node == nullptr)
        node = createBSTreeNode(value);
    else
    {
        if (node->value < value)
            addElement(node->rightChild, value);
        if (node->value > value)
            addElement(node->leftChild, value);
    }
}

void addElement(BSTree *tree, int value)
{
    addElement(tree->root, value);
}

void printIncreasingOrder(BSTreeNode *node)
{
    if (node != nullptr)
    {
        printIncreasingOrder(node->leftChild);
        cout << node->value << " ";
        printIncreasingOrder(node->rightChild);
    }
}

void printIncreasingOrder(BSTree *tree)
{
    printIncreasingOrder(tree->root);
}

void printDecreasingOrder(BSTreeNode *node)
{
    if (node != nullptr)
    {
        printDecreasingOrder(node->rightChild);
        cout << node->value << " ";
        printDecreasingOrder(node->leftChild);
    }
}

void printDecreasingOrder(BSTree *tree)
{
    printDecreasingOrder(tree->root);
}

void printPreorder(BSTreeNode *node)
{
    if (node != nullptr)
    {
        cout << "(" << node->value << " ";
        printPreorder(node->leftChild);
        printPreorder(node->rightChild);
        cout << ") ";
    }
    else
        cout << "NULL ";
}

void printPreorder(BSTree *tree)
{
    printPreorder(tree->root);
}

bool exists(BSTreeNode *node, int value)
{
    if (node != nullptr)
    {
        if (node->value < value)
            return exists(node->rightChild, value);
        if (node->value > value)
            return exists(node->leftChild, value);
        return true;
    }
    return false;
}

bool exists(BSTree *tree, int value)
{
    exists(tree->root, value);
}

enum NodeType
{
    noChildren,
    onlyLeftChild,
    onlyRightChild,
    twoChildren
};

NodeType determineType(BSTreeNode *node)
{
    if (node->leftChild == nullptr && node->rightChild == nullptr)
        return noChildren;
    if (node->leftChild == nullptr)
        return onlyRightChild;
    if (node->rightChild == nullptr)
        return onlyLeftChild;

    return twoChildren;
}


void removeNodeWithNoChildren(BSTreeNode* &node)
{
    delete node;
    node = nullptr;
}
void removeNodeWithLeftChild(BSTreeNode* &node)
{
    BSTreeNode* currentNode = node;
    node = node->leftChild;
    delete currentNode;
    currentNode = nullptr;
}
void removeNodeWithRightChild(BSTreeNode* &node)
{
    BSTreeNode *currentNode = node;
    node = node->rightChild;
    delete currentNode;
    currentNode = nullptr;
}

int findMin(BSTreeNode* node)
{
    while (node->leftChild != nullptr)
        node = node->leftChild;

    int value = node->value;

    return value;
}

void deleteElement(BSTreeNode* &node, int value);

void removeNodeWithTwoChildren(BSTreeNode* &node)
{
    int value = findMin(node->rightChild);
    deleteElement(node->rightChild, value);
    node->value = value;
}

void deleteElement(BSTreeNode* &node, int value)
{
    if (node != nullptr)
    {
        if (node->value == value)
        {
           NodeType currentNode = determineType(node);

           switch (currentNode)
           {
                case noChildren:
                    removeNodeWithNoChildren(node); break;
                case onlyLeftChild:
                    removeNodeWithLeftChild(node); break;
                case onlyRightChild:
                    removeNodeWithRightChild(node); break;
                case twoChildren:
                    removeNodeWithTwoChildren(node); break;
           }
        }
        else
            if (node->value > value)
                deleteElement(node->leftChild, value);
            else
                deleteElement(node->rightChild, value);
    }
}

void deleteElement(BSTree *tree, int value)
{
    return deleteElement(tree->root, value);
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
