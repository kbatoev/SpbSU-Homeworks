#pragma once

#include <iostream>

template <typename T>
class BSTree
{
public:
    BSTree() : root(nullptr)
    {}
    ~BSTree()
    {
        BSTree::Node::deleteNode(root);
    }

    /// cheking what element is in root
    T getTopValue()
    {
        if (root)
            return root->value;
    }

    void addElement(const T &valueToAdd)
    {
        BSTree::Node::addElement(root, valueToAdd);
    }
    bool exists(const T &valueToFind)
    {
        return BSTree::Node::exists(root, valueToFind);
    }
    void deleteElement(const T &valueToDelete)
    {
        BSTree::Node::deleteElement(root, valueToDelete);
    }

    void print()
    {
        BSTree::Node::print(root);
    }

private:
    class Node
    {
    public :
        T value;
        Node *leftChild;
        Node *rightChild;

        Node(T value) : value(value), leftChild(nullptr), rightChild(nullptr) {}
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
    };

    Node *root;
};

template <typename T>
void BSTree<T>::Node::deleteNode(BSTree::Node *&node)
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
void BSTree<T>::Node::addElement(BSTree::Node* &node, const T &valueToAdd)
{
    if (!node)
        node = new BSTree::Node(valueToAdd);
    else
    {
        if (node->value < valueToAdd)
            addElement(node->rightChild, valueToAdd);
        if (node->value > valueToAdd)
            addElement(node->leftChild, valueToAdd);
    }
}

template <typename T>
bool BSTree<T>::Node::exists(BSTree::Node *node, const T &valueToFind)
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
void BSTree<T>::Node::deleteElement(BSTree::Node* &node, const T &valueToDelete)
{
    if (node != nullptr)
    {
        if (node->value == valueToDelete)
        {
            BSTree::Node::NodeType currentNode = determineType(node);

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
        {
            if (node->value > valueToDelete)
                deleteElement(node->leftChild, valueToDelete);
            else
                deleteElement(node->rightChild, valueToDelete);
        }
    }
}

template <typename T>
typename BSTree<T>::Node::NodeType BSTree<T>::Node::determineType(BSTree::Node *node)
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
void BSTree<T>::Node::removeNodeWithNoChildren(BSTree::Node *&node)
{
    delete node;
    node = nullptr;
}

template <typename T>
void BSTree<T>::Node::removeNodeWithLeftChild(BSTree::Node *&node)
{
    Node* currentNode = node;
    node = node->leftChild;
    delete currentNode;
    currentNode = nullptr;
}

template <typename T>
void BSTree<T>::Node::removeNodeWithRightChild(BSTree::Node *&node)
{
    Node *currentNode = node;
    node = node->rightChild;
    delete currentNode;
    currentNode = nullptr;
}

template <typename T>
T BSTree<T>::Node::findMin(BSTree::Node *node)
{
    while (node->leftChild != nullptr)
        node = node->leftChild;
    int value = node->value;

    return value;
}

template <typename T>
void BSTree<T>::Node::removeNodeWithTwoChildren(BSTree::Node *&node)
{
    int value = findMin(node->rightChild);
    deleteElement(node->rightChild, value);
    node->value = value;
}

template <typename T>
void BSTree<T>::Node::print(BSTree::Node *node)
{
    if (node->leftChild)
        print(node->leftChild);
    std::cout << node->value << " ";
    if (node->rightChild)
        print(node->rightChild);
}
