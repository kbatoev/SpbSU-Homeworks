#include <iostream>

using namespace std;

int input()
{
	int number = 0;
	cout << "Enter an integer number, please:" << endl;
	cin >> number;
	return number;
}

void output(int item[], int pointer) 
{
	for (int i = 0; i < pointer; i++)
		cout << item[i] << " ";
	cout << endl;
}

void countSum(int balance, int lastNumber, int item[], int pointer) 
{	
	for (int i = lastNumber; i <= balance; i++)
	{
		item[pointer] = i;
		if (balance - i > 0)
			countSum(balance - i, i, item, pointer + 1);
		else
			output(item, pointer + 1);
	}
}


int main()
{

	const int maxSize = 1000;

	int number = input();

	int item[maxSize]; // массив слагаемых
	int pointer = 0;
	int lastNumber = 1;


	cout << "All sums are: " << endl;
	countSum(number, lastNumber, item, pointer);

	return 0;
}