#pragma once

#include <iostream>
#include <fstream>
#include "myString.h"

using namespace std;

struct List;

List *createList();

void addElement(MyString *line, List *list);
bool showNext(List *list);
int getAmount(List *list);

void printList(List *list);
void printList(List *list, ofstream &out);
void deleteList(List *list);

bool isInList(MyString *line, List *list);
