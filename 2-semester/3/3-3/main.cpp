#include <iostream>
#include "linkedList.h"
#include "comparable.h"
#include "sortedSet.h"

using namespace std;

int main()
{

    int amount = 0;
    cout << "How many lists do you want ?\n";
    cin >> amount;

    SortedSet *set = new SortedSet;
    for (int i = 0; i < amount; i++)
    {
        LinkedList *list = new LinkedList;
        cout << i + 1 << ": You will enter while entered number is not 0\n";
        int number = 1;
        while (number)
        {
            cin >> number;
            if (number)
                list->add(number);
        }
        set->add(list);
    }

    cout << "Set is:\n";
    set->print();

    delete set;
    return 0;
}

