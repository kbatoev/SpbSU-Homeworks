#include <iostream>
#include "stack.h"
#include "postfix.h"

using namespace std;

int main()
{
	const int maxSize = 1000;
	
	char *infix = new char[maxSize];

	cout << "Enter a mathematical expression:" << endl;
	cin >> infix;

	char *postfix = convertToPostfix(infix);

	cout << "This is postfix notation of expression:" << endl;
	cout << postfix << endl;

	delete[] infix;
	delete[] postfix;

	return 0;
}