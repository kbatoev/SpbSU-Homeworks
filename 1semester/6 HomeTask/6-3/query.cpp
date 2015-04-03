#include "query.h"

void addToTree(Tree *tree)
{
    int value = 0;
    cout << "Enter a value: ";
    cin >> value;
    addElement(tree, value);
    cout << "I've added." << endl;
}

void deleteFromTree(Tree *tree)
{
    int value = 0;
    cout << "Enter a value: ";
    cin >> value;
    deleteElement(tree, value);
    cout << "I've deleted" << endl;
}

void subsists(Tree *tree)
{
    int value = 0;
    cout << "Enter a value to check whether it is in BST: ";
    cin >> value;
    if (exists(tree, value))
        cout << "Yes, it does" << endl;
    else
        cout << "No, it doesn't" << endl;
}

void showDecrescentOrder(Tree *tree)
{
    cout << "That's is Decreasing order:" << endl;
    printDecreasingOrder(tree);
    cout << endl;
}

void showIncrescentOrder(Tree *tree)
{
    cout << "That's is Increasing order:" << endl;
    printIncreasingOrder(tree);
    cout << endl;
}

void showPreorder(Tree *tree)
{
    cout << "That's is preorder:" << endl;
    printPreorder(tree);
    cout << endl;
}

void startMenu()
{
    cout << "You can do such actions: " << endl;
    cout << "1 - add value to Tree" << endl;
    cout << "2 - delete value from Tree" << endl;
    cout << "3 - check exists value or not" << endl;
    cout << "4 - print elements in increasing way" << endl;
    cout << "5 - print elements in decreasing way" << endl;
    cout << "6 - print elements in preorder way" << endl;
    cout << "0 - exit" << endl;
}

