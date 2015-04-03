#include <iostream>
#include "query.h"

using namespace std;

int main()
{
    enum Operations
    {
        addValue = 1,
        deleteValue,
        isMemberOfTree,
        printIncrescentOrder,
        printDecrescentOrder,
        printStraightOrder,
        start
    };

    Tree *tree = createTree();



    Operations action = start;
    while (action)
    {
        startMenu();
        int currentAction = 0;
        cin >> currentAction;
        action = (Operations) currentAction;

        switch (action)
        {
        case addValue:
            addToTree(tree); break;
        case deleteValue:
            deleteFromTree(tree); break;
        case isMemberOfTree:
            subsists(tree); break;
        case printIncrescentOrder:
            showIncrescentOrder(tree); break;
        case printDecrescentOrder:
            showDecrescentOrder(tree); break;
        case printStraightOrder:
            showPreorder(tree);
        }
    }

    deleteTree(tree);

    return 0;
}

