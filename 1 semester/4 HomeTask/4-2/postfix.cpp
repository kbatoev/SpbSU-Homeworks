#include "postfix.h"

char *convertToPostfix(char *infix)
{	
	const char space = ' ';
	const int maxSize = 1000;

	Stack *stack = createStack();
	char *postfix = new char[maxSize];
	int current = 0;
	
	int i = 0;
	while (infix[i] != '\0')
	{
		if (isNumber(infix[i]))
		{
			postfix[current++] = infix[i];
			postfix[current++] = space;
		}
		else
		if (infix[i] == '(')
			push(stack, "(");
		else
		if (infix[i] == ')')
		{
			while (top(stack) != "(")
			{
				char *action = pop(stack);
				postfix[current++] = action[0];
				postfix[current++] = space;
			}
			pop(stack);
		}
		else
		{	
			char *previousAction = top(stack);
			while (!isEmpty(stack) && countPriority(infix[i]) <= countPriority(previousAction[0]))
			{
				postfix[current++] = previousAction[0];
				postfix[current++] = space;
				pop(stack);
				previousAction = top(stack);
			}
			char *action = new char[maxSize];
			action[0] = infix[i];
			push(stack, action);
		}

		i++;
	}

	while (!isEmpty(stack))
	{
		char *action = pop(stack);
		postfix[current++] = action[0];
		postfix[current++] = space;
	}

	deleteStack(stack);
	postfix[current] = '\0';

	return postfix;
}

bool isNumber(char symbol)
{
	return (symbol >= '0' && symbol <= '9');
}

int countPriority(char action)
{
	if (action == '+' || action == '-')
		return 1;
	else
	if (action == '*' || action == '/')
		return 2;
	else
		return -1;
}