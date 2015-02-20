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

    BSTree *tree = createBSTree();

    startMenu();

    Operations action = start;
    while (action)
    {
        int currentAction = 0;
        cin >> currentAction;
        action = (Operations) currentAction;

        switch (action)
        {
        case addValue:
            addToBST(tree); break;
        case deleteValue:
            deleteFromBST(tree); break;
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

    deleteBSTree(tree);

    return 0;
}

