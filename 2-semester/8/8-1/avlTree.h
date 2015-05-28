#pragma once

#include <iostream>

template <typename T>
class AVLTree
{
public:
    AVLTree() : root(nullptr)
    {}
    ~AVLTree();

    /// cheking what element is in root
    T getTopValue();
    void addElement(const T &valueToAdd)
    {
        AVLTree::Node::addElement(root, valueToAdd);
    }
    bool exists(const T &valueToFind) {
        return AVLTree::Node::exists(root, valueToFind);
    }
    void deleteElement(const T &valueToDelete)
    {
        AVLTree::Node::deleteElement(root, valueToDelete);
    }

    void print()
    {
        AVLTree::Node::print(root);
    }

private:
    class Node
    {
    public :
        T value;
        int height;
        /**
         * @brief copies - shows number of elements with given Value
         */
        int copies;
        Node *leftChild;
        Node *rightChild;

        Node(T value) : value(value), height(1), copies(1), leftChild(nullptr), rightChild(nullptr)
        {}
        /// deletes Node, but not its children
        ~Node() {}

        static void addElement(Node* &node, const T &valueToAdd);
        static bool exists(Node *node, const T &valueToFind);
        static void deleteElement(Node* &node, const T &valueToDelete);
        static void print(Node *node);

        /// deletes Node, and its children
        static void deleteNode(Node* &node);

    private:
        enum NodeType
        {
            noChildren,
            onlyLeftChild,
            onlyRightChild,
            twoChildren
        };
        static NodeType determineType(Node *node);
        static void removeNodeWithNoChildren(Node* &node);
        static void removeNodeWithLeftChild(Node* &node);
        static void removeNodeWithRightChild(Node* &node);
        static T findMin(Node *node);
        static void removeNodeWithTwoChildren(Node* &node);

        static int countHeight(Node *node);
        static int balanceFactor(Node *node);
        static void updateHeight(Node *node);

        static Node* rotateRight(Node *node);
        static Node* rotateLeft(Node *node);
        static Node* balance(Node *node);

    };

    Node *root;
};

template <typename T>
AVLTree<T>::~AVLTree()
{
    AVLTree::Node::deleteNode(root);
}

template <typename T>
T AVLTree<T>::getTopValue()
{
    if (root)
        return root->value;
}

template <typename T>
int AVLTree<T>::Node::countHeight(AVLTree::Node *node)
{
    return node ? node->height : 0;
}

template <typename T>
int AVLTree<T>::Node::balanceFactor(AVLTree::Node *node)
{
    return countHeight(node->rightChild) - countHeight(node->leftChild);
}

template <typename T>
void AVLTree<T>::Node::updateHeight(AVLTree::Node *node)
{
    int heightLeft = countHeight(node->leftChild);
    int heightRight = countHeight(node->rightChild);
    node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::Node::rotateRight(AVLTree::Node *node)
{
    Node *pivot = node->leftChild;
    node->leftChild = pivot->rightChild;
    pivot->rightChild = node;
    updateHeight(node);
    updateHeight(pivot);
    return pivot;
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::Node::rotateLeft(AVLTree::Node *node)
{
    Node *pivot = node->rightChild;
    node->rightChild = pivot->leftChild;
    pivot->leftChild = node;
    updateHeight(node);
    updateHeight(pivot);
    return pivot;
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::Node::balance(AVLTree::Node *node)
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

template <typename T>
void AVLTree<T>::Node::deleteNode(AVLTree::Node *&node)
{
    if (node != nullptr)
    {
        deleteNode(node->leftChild);
        deleteNode(node->rightChild);
        delete node;
        node = nullptr;
    }
}

template <typename T>
void AVLTree<T>::Node::addElement(AVLTree::Node* &node, const T &valueToAdd)
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

template <typename T>
bool AVLTree<T>::Node::exists(AVLTree::Node *node, const T &valueToFind)
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

template <typename T>
void AVLTree<T>::Node::deleteElement(AVLTree::Node* &node, const T &valueToDelete)
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

template <typename T>
typename AVLTree<T>::Node::NodeType AVLTree<T>::Node::determineType(AVLTree::Node *node)
{
    if (node->leftChild == nullptr && node->rightChild == nullptr)
        return noChildren;
    if (node->leftChild == nullptr)
        return onlyRightChild;
    if (node->rightChild == nullptr)
        return onlyLeftChild;

    return twoChildren;
}

template <typename T>
void AVLTree<T>::Node::removeNodeWithNoChildren(AVLTree::Node *&node)
{
    delete node;
    node = nullptr;
}

template <typename T>
void AVLTree<T>::Node::removeNodeWithLeftChild(AVLTree::Node *&node)
{
    Node* currentNode = node;
    node = node->leftChild;
    delete currentNode;
    currentNode = nullptr;
}

template <typename T>
void AVLTree<T>::Node::removeNodeWithRightChild(AVLTree::Node *&node)
{
    Node *currentNode = node;
    node = node->rightChild;
    delete currentNode;
    currentNode = nullptr;
}

template <typename T>
T AVLTree<T>::Node::findMin(AVLTree::Node *node)
{
    while (node->leftChild != nullptr)
        node = node->leftChild;
    int value = node->value;

    return value;
}

template <typename T>
void AVLTree<T>::Node::removeNodeWithTwoChildren(AVLTree::Node *&node)
{
    int value = findMin(node->rightChild);
    deleteElement(node->rightChild, value);
    node->value = value;
}

template <typename T>
void AVLTree<T>::Node::print(AVLTree::Node *node)
{
    if (node->leftChild)
        print(node->leftChild);
    std::cout << node->value << " ";
    if (node->rightChild)
        print(node->rightChild);
}
