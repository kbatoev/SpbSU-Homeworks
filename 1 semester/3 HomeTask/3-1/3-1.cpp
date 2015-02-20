#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	List *list = createList();

	int number = 0;
	int step = 0;

	cout << "Enter 2 integers numbers: size of squad and step:" << endl;
	cin >> number >> step;
	for (int i = 1; i <= number; i++)
		addElement(i, list);

	ListElement *guard = list->head;
	ListElement *previousElement = guard;
	for (int i = 0; i < number - 1; i++)
		previousElement = removeElement(step, previousElement, list);

	ListElement *currentElement = previousElement->next;
	cout << "A person on position " << currentElement->value << " will survive" << endl;

	deleteList(list);

	return 0;
}