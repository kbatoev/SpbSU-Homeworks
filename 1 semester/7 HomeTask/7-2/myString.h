#pragma once

#include <iostream>
#include <string.h>

using namespace std;

struct MyString;

MyString *createString();
void deleteString(MyString *myString);
MyString *cloneString(MyString *myString);

void printString(MyString *myString);
void concatenateStrings(MyString *myString, MyString *tail);

bool areEqual(MyString *first, MyString *second);
int countLength(MyString *myString);
bool isEmpty(MyString *myString);
MyString *chooseSubstring(MyString *myString);
char *convertToChar(MyString *myString);
