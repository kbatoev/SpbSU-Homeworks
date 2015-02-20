#pragma once

#include "stack.h"

int createIntNumber(char *number);
char *createStringNumber(int number);

int countOperator(int first, int second, char action);
int countExpression(char *postfix);

bool isNumber(char symbol);
bool isNumber(char symbol, char nextSymbol);
bool isOperator(char symbol);