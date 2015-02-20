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
	list->head = createListElement(0, NULL);
	list->head->next = list->head;
	return list;
}

void deleteList(List *list)
{
	int step = 1;
	ListElement *guard = list->head;
	removeElement(step, guard, list);
	delete guard;
	delete list;
}

void addElement(int number, List *list)
{
	ListElement *guard = list->head;
	addElement(number, guard);
}

void addElement(int number, ListElement *guard)
{
	ListElement *currentElement = guard;
	ListElement *nextElement = currentElement->next;

	if (nextElement == guard)
	{
		ListElement *element = createListElement(number, NULL);
		element->next = element;
		guard->next = element;
	}
	else
	{
		currentElement = nextElement;
		nextElement = currentElement->next;
		while (nextElement != guard->next)
		{
			currentElement = nextElement;
			nextElement = currentElement->next;
		}
	
		ListElement *element = createListElement(number, guard->next);
		currentElement->next = element;
	}
}

ListElement *removeElement(int step, ListElement *previousElement, List *list)
{
	ListElement *guard = list->head;
	ListElement *currentElement = previousElement->next;

	for (int i = 0; i < step - 1; i++)
	{
		previousElement = currentElement;
		currentElement = currentElement->next;
	}

	ListElement *foundElement = currentElement;
	
	if (currentElement == guard->next)
	{
		guard->next = currentElement->next;
	}
	previousElement->next = currentElement->next;

	delete foundElement;

	return previousElement;
}