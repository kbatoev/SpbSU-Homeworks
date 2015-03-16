#include <iostream>
#include "linkedList.h"
#include "sortedSet.h"

using namespace std;

int main()
{
    SortedSet *set = new SortedSet;

    LinkedList *list1 = new LinkedList;
    for (int i = 0; i < 10; i++)
        list1->add(i + 1);

    set->addList(list1);

    LinkedList *list2 = new LinkedList;
    for (int i = 0; i < 5; i++)
        list2->add(i + 1);

    set->addList(list2);

    LinkedList *list3 = new LinkedList;
    for (int i = 0; i < 100; i++)
        list3->add(i + 1);
    set->addList(list3);

    cout << "Size of set is " << set->getSizeOfSet() << endl;


    delete list1;
    delete list2;
    delete list3;

    set->printSet();

    delete set;

    return 0;
}

