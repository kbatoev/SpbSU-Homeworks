#include "count.h"

int createIntNumber(char *number)
{
	const int base = 10;
	const char zero = '0';
	
	int first = 0;
	if (number[0] == '-')
		first = 1;

	int result = 0;
	int i = first;
	while (isNumber(number[i]))
	{
		result = result * base + number[i] - zero;
		i++;
	}
	if (first)
		result *= -1;

	return result;
}

char *createStringNumber(int number)
{
	const int maxSize = 1000;
	const int base = 10;
	const char zero = '0';

	char *result = new char[maxSize];
	int current = 0;

	if (number < 0)
	{
		result[current++] = '-';
		number *= -1;
	}

	char *temp = new char[maxSize];
	int i = 0;
	while (number > 0)
	{
		char figure = (number % base) + zero;
		temp[i++] = figure;
		number /= 10;
	}
	i--;
	while (i >= 0)
	{
		result[current++] = temp[i--];
	}

	if (!current)
		result[current] = zero;
	
	return result;
}

int countOperator(int first, int second, char action)
{
	if (action == '+')
		return first + second;
	if (action == '-')
		return first - second;
	if (action == '*')
		return first * second;
	if (action == '/')
		return first / second;
}

int countExpression(char *postfix)
{
	const int maxSize = 1000;
	const char space = ' ';

	int result = 0;
	Stack *stack = createStack();
	
	int i = 0;
	while (postfix[i] != '\0')
	{
		if (postfix[i] != space)
			if (isNumber(postfix[i], postfix[i+1]))
			{
				char *number = new char[maxSize];
				int current = 0;
				number[current++] = postfix[i++];
				while (isNumber(postfix[i]))
				{
					number[current++] = postfix[i++];
				}
				i--;
				push(stack, number);
			}
			else
			if (isOperator(postfix[i]))
			{
				int second = createIntNumber(pop(stack));
				int first = createIntNumber(pop(stack));
				
				int third = countOperator(first, second, postfix[i]);

				push(stack, createStringNumber(third));
			}
		i++;
	}
	result = createIntNumber(pop(stack));
	deleteStack(stack);

	return result;
}

bool isNumber(char symbol)
{
	return (symbol >= '0' && symbol <= '9');
}

bool isNumber(char symbol, char nextSymbol)
{
	return (isNumber(symbol) || (symbol == '-' && isNumber(nextSymbol)));
}

bool isOperator(char symbol)
{
	return (symbol == '+' || symbol == '-' 
		|| symbol == '*' || symbol == '/');
}