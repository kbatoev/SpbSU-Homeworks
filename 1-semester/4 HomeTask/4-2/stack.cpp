#include "stack.h"

StackElement *createStackElement(StackElement *next, char *value)
{
	StackElement *element = new StackElement;
	element->value = value;
	element->next = next;
	return element;
}


Stack *createStack()
{
	Stack *newStack = new Stack;
	newStack->top = createStackElement(NULL, "");
	return newStack;
}

void push(Stack *stack, char *value)
{
	StackElement *element = createStackElement(stack->top->next, value);
	stack->top->next = element;
}

char *pop(Stack *stack)
{
	const int maxSize = 1000;
	char *result = new char[maxSize];
	StackElement *element = stack->top->next;
	result = element->value;
	stack->top->next = element->next;
	delete element;
	return result;
}

bool isEmpty(Stack *stack)
{
	return stack->top->next == NULL;
}

void deleteStack(Stack *stack)
{
	while (!isEmpty(stack))
		pop(stack);
	delete stack->top;
	delete stack;
}

char *top(Stack *stack)
{
	if (!isEmpty(stack))
		return stack->top->next->value;
}