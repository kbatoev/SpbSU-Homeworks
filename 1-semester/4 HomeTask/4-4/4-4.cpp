#include <iostream>
#include "stack.h"
#include "count.h"
#include "postfix.h"

using namespace std;

int main()
{
	const int maxSize = 1000;
	char *infix = new char[maxSize];
	
	cout << "Enter a mathematical expression:" << endl;
	cin >> infix;

	char *postfix = convertToPostfix(infix);

	int result = countExpression(postfix);

	cout << "I've counted value:" << endl;
	cout << result << endl;

	delete[] infix;
	delete[] postfix;

	return 0;
}