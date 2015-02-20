#pragma once

#include <stdlib.h> 

struct StackElement
{
	char *value;
	StackElement *next;
};

struct Stack
{
	StackElement *top;
};

Stack *createStack();
void deleteStack(Stack *stack);

void push(Stack *stack, char *value);
char *pop(Stack *stack);
char *top(Stack *stack);
bool isEmpty(Stack *stack);
