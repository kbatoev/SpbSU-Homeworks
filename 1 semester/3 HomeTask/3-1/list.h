#pragma once

#include <iostream>

struct ListElement
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement *head;		
};

List *createList();
ListElement *createListElement(int value, ListElement *next);

void addElement(int number, ListElement *guard);
void addElement(int number, List *list);

ListElement *removeElement(int number, ListElement *previousElement, List *list);

void deleteList(List *list);