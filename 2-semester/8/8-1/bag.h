#pragma once

/**
 * Template class Bag.
 * It can keep a multiset with repetitions of elements.
 * To improve run-time - structure of AVL-Trees is used.
 */


template <typename T>
class Bag
{
public:
    Bag() : root(nullptr)
    {}
    ~Bag();

    /// cheking what element is in root
    T getTopValue();
    void addElement(const int &valueToAdd) {Bag::Node::addElement(root, valueToAdd);}
    bool exists(const int &valueToFind) {return Bag::Node::exists(root, valueToFind);}
    void deleteElement(const int &valueToDelete) {Bag::Node::deleteElement(root, valueToDelete);}

private:
    class Node
    {
    public :
        int value;
        int height;
        /**
         * @brief copies - shows number of elements with given Value
         */
        int copies;
        Node *leftChild;
        Node *rightChild;

        Node(int value) : value(value), height(1), copies(1), leftChild(nullptr), rightChild(nullptr)
        {}
        /// deletes Node, but not its children
        ~Node() {}

        static void addElement(Node* &node, const int &valueToAdd);
        static bool exists(Node *node, const int &valueToFind);
        static void deleteElement(Node* &node, const int &valueToDelete);

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


        /// functions of AVL-Tree, to make tree be balanced
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
Bag<T>::~Bag()
{
    Bag::Node::deleteNode(root);
}

template <typename T>
T Bag<T>::getTopValue()
{
    if (root)
        return root->value;
}

template <typename T>
int Bag<T>::Node::countHeight(Bag::Node *node)
{
    return node ? node->height : 0;
}

template <typename T>
int Bag<T>::Node::balanceFactor(Bag::Node *node)
{
    return countHeight(node->rightChild) - countHeight(node->leftChild);
}

template <typename T>
void Bag<T>::Node::updateHeight(Bag::Node *node)
{
    int heightLeft = countHeight(node->leftChild);
    int heightRight = countHeight(node->rightChild);
    node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

template <typename T>
typename Bag<T>::Node* Bag<T>::Node::rotateRight(Bag::Node *node)
{
    Node *pivot = node->leftChild;
    node->leftChild = pivot->rightChild;
    pivot->rightChild = node;
    updateHeight(node);
    updateHeight(pivot);
    return pivot;
}

template <typename T>
typename Bag<T>::Node *Bag<T>::Node::rotateLeft(Bag::Node *node)
{
    Node *pivot = node->rightChild;
    node->rightChild = pivot->leftChild;
    pivot->leftChild = node;
    updateHeight(node);
    updateHeight(pivot);
    return pivot;
}

template <typename T>
typename Bag<T>::Node *Bag<T>::Node::balance(Bag::Node *node)
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
void Bag<T>::Node::deleteNode(Bag::Node *&node)
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
void Bag<T>::Node::addElement(Bag::Node* &node, const int &valueToAdd)
{
    if (!node)
        node = new Bag::Node(valueToAdd);
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
bool Bag<T>::Node::exists(Bag::Node *node, const int &valueToFind)
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
void Bag<T>::Node::deleteElement(Bag::Node* &node, const int &valueToDelete)
{
    if (node != nullptr)
    {
        if (node->value == valueToDelete)
        {
            if (node->copies == 1)
            {
                Bag::Node::NodeType currentNode = determineType(node);

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
typename Bag<T>::Node::NodeType Bag<T>::Node::determineType(Bag::Node *node)
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
void Bag<T>::Node::removeNodeWithNoChildren(Bag::Node *&node)
{
    delete node;
    node = nullptr;
}

template <typename T>
void Bag<T>::Node::removeNodeWithLeftChild(Bag::Node *&node)
{
    Node* currentNode = node;
    node = node->leftChild;
    delete currentNode;
    currentNode = nullptr;
}

template <typename T>
void Bag<T>::Node::removeNodeWithRightChild(Bag::Node *&node)
{
    Node *currentNode = node;
    node = node->rightChild;
    delete currentNode;
    currentNode = nullptr;
}

template <typename T>
T Bag<T>::Node::findMin(Bag::Node *node)
{
    while (node->leftChild != nullptr)
        node = node->leftChild;

    int value = node->value;

    return value;
}

template <typename T>
void Bag<T>::Node::removeNodeWithTwoChildren(Bag::Node *&node)
{
    int value = findMin(node->rightChild);
    deleteElement(node->rightChild, value);
    node->value = value;
}


