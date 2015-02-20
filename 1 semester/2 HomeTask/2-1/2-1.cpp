#include <iostream>

using namespace std;

int input()
{
	int number = 0;
	cout << "Enter an integer number, please:" << endl;
	cin >> number;
	return number;
}

int recursiveFibonacci(int number)
{
	if (number < 1)
		return 0;
	else
		if (number < 2)
			return 1;
		else
			return recursiveFibonacci(number - 1) + recursiveFibonacci(number - 2);
}


int iterativeFibonacci(int number)
{
	
	int first = 0;
	int second = 1;
	int necessaryNumber = 1;
	for (int i = 2; i <= number; i++)
	{
		necessaryNumber = second + first;
		first = second;
		second = necessaryNumber;
	}

	return necessaryNumber;
}

void output(int recNumber, int iterNumber) 
{
	cout << "Recursive algorithm counted this Fibonacci Number: " << recNumber << endl;
	cout << "And iterative algorithm counted this Fibonacci Number: " << iterNumber << endl;
}

int main()
{

	int number = input();
	
	int recNumber = recursiveFibonacci(number); 
	int iterNumber = iterativeFibonacci(number);

	output(recNumber, iterNumber);

	return 0;
}