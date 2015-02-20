#pragma once

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct MyString;

MyString *readString();
MyString *readString(ifstream &in);
void deleteString(MyString *myString);
MyString *cloneString(MyString *myString);

void printString(MyString *myString);
void concatenateStrings(MyString *myString, MyString *tail);

bool areEqual(MyString *first, MyString *second);
int getLength(MyString *myString);
bool isEmpty(MyString *myString);
MyString *chooseSubstring(MyString *myString, int index, int length);
char *convertToChar(MyString *myString);
