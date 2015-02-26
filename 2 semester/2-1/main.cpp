#include <iostream>
#include "linkedList.h"

using namespace std;

int main()
{
    LinkedList *list = new LinkedList;
    list->add(15);
    list->add(90);
    if (!list->remove(16))
        cout << "True" << endl;
    list->printList();
    list->add(56);


    return 0;
}

