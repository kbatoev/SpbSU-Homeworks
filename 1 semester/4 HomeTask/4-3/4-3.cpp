#include <iostream>
#include "stack.h"
#include "count.h"

using namespace std;

int main()
{
	const int maxSize = 1000;
	char *postfix = new char[maxSize];

	cout << "Enter a mathematical expression in postfix notation:" << endl;
	fgets(postfix, maxSize, stdin);

	int result = countExpression(postfix); 

	cout << "I've counted your expression:" << endl;
	cout << result << endl;

	delete[] postfix;

	return 0;
}