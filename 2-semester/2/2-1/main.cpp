#include <iostream>
#include "linkedList.h"
#include "doublyLinkedList.h"
#include "linkedListTest.h"
#include "doublyLinkedListTest.h"

int main()
{
    std::cout << "TESTING OF LINKED LIST:\n";
    LinkedListTest linkedListTest;
    QTest::qExec(&linkedListTest);

    std::cout << "\n\nTESTING OF DOUBLY LINKED LIST:\n";
    DoublyLinkedListTest doublyListTest;
    QTest::qExec(&doublyListTest);


    return 0;
}

