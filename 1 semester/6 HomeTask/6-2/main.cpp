#include <iostream>
#include "bst.h"

using namespace std;

int readNumber(char &symbol, int &balance)
{
    int sum = 0;
    while (symbol >= '0' && symbol <= '9')
    {
        sum = sum * 10 + (symbol - '0');
        symbol = getchar();
    }
    if (symbol == ')')
    {
        balance--;
        symbol = ' ';
    }
    return sum;
}

int main()
{
    const char nonOperation = 'a';
    const int nonNumber = 0;

    cout << "Enter a maths expression: " << endl;
    BSTree *tree = createBSTree();
    int balance = 0;
    char symbol = ' ';
    do
    {
        if (symbol == ' ')
            symbol = getchar();
        switch (symbol)
        {
        case '(':
            balance++;
            char operation;
            cin >> operation;
            addElement(tree, nonNumber, operation);
            symbol = ' ';
            break;
        case ')':
            balance--;
            symbol = ' ';
            break;
        case ' ':
            break;
        default:
            int number = readNumber(symbol, balance);
            addElement(tree, number, nonOperation);
            break;
        }

    }while (balance);

    cout << "This is infix notation of expression: " << endl;
    printInfix(tree);
    cout << endl;
    int result = countExpression(tree);
    cout << "Result is: " << result << endl;

    deleteBSTree(tree);

    return 0;
}

