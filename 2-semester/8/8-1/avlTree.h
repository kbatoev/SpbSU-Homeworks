#pragma once

class AVLTree
{
public:
    AVLTree() : root(nullptr)
    {}
    ~AVLTree();

    int getTopValue();
    void addElement(int valueToAdd) {AVLTree::Node::addElement(root, valueToAdd);}
    bool exists(int valueToFind) {return AVLTree::Node::exists(root, valueToFind);}
    void deleteElement(int valueToDelete) {AVLTree::Node::deleteElement(root, valueToDelete);}

private:
    class Node
    {
    public :
        int value;
        int height;
        int copies;
        Node *leftChild;
        Node *rightChild;

        Node(int value) : value(value), height(1), copies(1), leftChild(nullptr), rightChild(nullptr)
        {}
        ~Node();

        static void addElement(Node* &node, int valueToAdd);
        static bool exists(Node *node, int valueToFind);
        static void deleteElement(Node* &node, int valueToDelete);
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
        static int findMin(Node *node);
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
