#include <iostream>
#include "linkedList.h"
#include "doublyLinkedList.h"

using namespace std;

int main()
{
    /*
    LinkedList *list = new LinkedList;
    list->add(15);
    list->add(90);
    if (!list->remove(16))
        cout << "True" << endl;
    list->printList();
    list->add(56);
    */

    DoublyLinkedList *doubleList = new DoublyLinkedList;

    doubleList->add(1);
    doubleList->add(2);
    doubleList->add(3);
    doubleList->add(4);
    doubleList->add(5);
    doubleList->printList();
    doubleList->remove(3);
    doubleList->printList();


    return 0;
}

