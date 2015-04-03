#pragma once

#include <iostream>

using namespace std;

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
void addElement(int number, List *sortedList);

void removeElement(int number, ListElement *guard);
void removeElement(int number, List *sortedList);

void printList(List *sortedList);

void deleteList(List *sortedList);