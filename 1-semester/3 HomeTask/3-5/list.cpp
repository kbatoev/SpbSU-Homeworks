#include "list.h"

ListElement *createListElement(int value, ListElement *next)
{
	ListElement *element = new ListElement;
	element->value = value;
	element->next = next;
	return element;
}

List *createList()
{
	List *list = new List;
	ListElement *guard = createListElement(0, NULL);
	list->head = guard;
	return list;
}

void addElement(int number, List *sortedList)
{
	ListElement *guard = sortedList->head;
	addElement(number, guard);
}

void addElement(int number, ListElement *guard)
{
	ListElement *currentElement = guard;
	ListElement *nextElement = currentElement->next;

	while (nextElement != NULL && nextElement->value < number)
	{
		currentElement = nextElement;
		nextElement = currentElement->next;
	}

	ListElement *element = createListElement(number, nextElement);
	currentElement->next = element;
}

void printList(List *sortedList)
{
	ListElement *currentElement = sortedList->head->next;

	while (currentElement != NULL)
	{
		cout << currentElement->value << " ";
		currentElement = currentElement->next;
	}
	cout << endl;
}

void removeElement(int number, List *sortedList)
{
	removeElement(number, sortedList->head);
}

void removeElement(int number, ListElement *guard)
{
	ListElement *currentElement = guard;
	ListElement *nextElement = currentElement->next;

	while (nextElement != NULL)
	{
		if (nextElement->value == number)
		{
			ListElement *foundElement = nextElement;
			currentElement->next = nextElement->next;
			delete nextElement;
			break;
		}
		currentElement = nextElement;
		nextElement = currentElement->next;
	}
}

void deleteList(List *sortedList)
{
	ListElement *element = sortedList->head;
	ListElement *next = element->next;
	while (next != NULL)
	{
		delete element;
		element = next;
		next = element->next;
	}
	delete element;
	delete sortedList;
}