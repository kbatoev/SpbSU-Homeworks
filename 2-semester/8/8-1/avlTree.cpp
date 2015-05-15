#include "avlTree.h"

AVLTree::~AVLTree()
{
    AVLTree::Node::deleteNode(root);
}

int AVLTree::getTopValue()
{
    if (root)
        return root->value;
}

AVLTree::Node::~Node()
{}

int AVLTree::Node::countHeight(AVLTree::Node *node)
{
    return node ? node->height : 0;
}

int AVLTree::Node::balanceFactor(AVLTree::Node *node)
{
    return countHeight(node->rightChild) - countHeight(node->leftChild);
}

void AVLTree::Node::updateHeight(AVLTree::Node *node)
{
    int heightLeft = countHeight(node->leftChild);
    int heightRight = countHeight(node->rightChild);
    node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

AVLTree::Node *AVLTree::Node::rotateRight(AVLTree::Node *node)
{
    Node *pivot = node->leftChild;
    node->leftChild = pivot->rightChild;
    pivot->rightChild = node;
    updateHeight(node);
    updateHeight(pivot);
    return pivot;
}

AVLTree::Node *AVLTree::Node::rotateLeft(AVLTree::Node *node)
{
    Node *pivot = node->rightChild;
    node->rightChild = pivot->leftChild;
    pivot->leftChild = node;
    updateHeight(node);
    updateHeight(pivot);
    return pivot;
}

AVLTree::Node *AVLTree::Node::balance(AVLTree::Node *node)
{
    updateHeight(node);
    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->rightChild) < 0)
            node->rightChild = rotateRight(node->rightChild);

        return rotateLeft(node);
    }
    if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->leftChild) > 0)
            node->leftChild = rotateLeft(node->leftChild);

        return rotateRight(node);
    }
    return node;
}

void AVLTree::Node::deleteNode(AVLTree::Node *&node)
{
    if (node != nullptr)
    {
        deleteNode(node->leftChild);
        deleteNode(node->rightChild);
        delete node;
        node = nullptr;
    }
}

void AVLTree::Node::addElement(AVLTree::Node* &node, int valueToAdd)
{
    if (!node)
        node = new AVLTree::Node(valueToAdd);
    else
    {
        if (node->value < valueToAdd)
            addElement(node->rightChild, valueToAdd);
        if (node->value > valueToAdd)
            addElement(node->leftChild, valueToAdd);
        if (node->value == valueToAdd)
            node->copies++;
        node = balance(node);
    }
}

bool AVLTree::Node::exists(AVLTree::Node *node, int valueToFind)
{
    if (node)
    {
        if (node->value < valueToFind)
            return exists(node->rightChild, valueToFind);
        if (node->value > valueToFind)
            return exists(node->leftChild, valueToFind);
        return true;
    }
    return false;
}

void AVLTree::Node::deleteElement(AVLTree::Node* &node, int valueToDelete)
{
    if (node != nullptr)
    {
        if (node->value == valueToDelete)
        {
            if (node->copies == 1)
            {
                AVLTree::Node::NodeType currentNode = determineType(node);

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
                node->copies--;
        }
        else
        {
            if (node->value > valueToDelete)
                deleteElement(node->leftChild, valueToDelete);
            else
                deleteElement(node->rightChild, valueToDelete);
            node = balance(node);
        }
    }
}

AVLTree::Node::NodeType AVLTree::Node::determineType(AVLTree::Node *node)
{
    if (node->leftChild == nullptr && node->rightChild == nullptr)
        return noChildren;
    if (node->leftChild == nullptr)
        return onlyRightChild;
    if (node->rightChild == nullptr)
        return onlyLeftChild;

    return twoChildren;
}

void AVLTree::Node::removeNodeWithNoChildren(AVLTree::Node *&node)
{
    delete node;
    node = nullptr;
}

void AVLTree::Node::removeNodeWithLeftChild(AVLTree::Node *&node)
{
    Node* currentNode = node;
    node = node->leftChild;
    delete currentNode;
    currentNode = nullptr;
}

void AVLTree::Node::removeNodeWithRightChild(AVLTree::Node *&node)
{
    Node *currentNode = node;
    node = node->rightChild;
    delete currentNode;
    currentNode = nullptr;
}

int AVLTree::Node::findMin(AVLTree::Node *node)
{
    while (node->leftChild != nullptr)
        node = node->leftChild;

    int value = node->value;

    return value;
}

void AVLTree::Node::removeNodeWithTwoChildren(AVLTree::Node *&node)
{
    int value = findMin(node->rightChild);
    deleteElement(node->rightChild, value);
    node->value = value;
}

