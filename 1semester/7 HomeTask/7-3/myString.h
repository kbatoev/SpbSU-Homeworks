#pragma once

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct MyString;

MyString *createString();
MyString *createString(char *line);
void deleteString(MyString *myString);
MyString *cloneString(MyString *myString);

void printString(MyString *myString);
void printString(MyString *myString, ofstream &out);
void concatenateStrings(MyString *myString, MyString *tail);

bool areEqual(MyString *first, MyString *second);
int countLength(MyString *myString);
bool isEmpty(MyString *myString);
MyString *chooseSubstring(MyString *myString);
char *convertToChar(MyString *myString);
