#include <iostream>

using namespace std;

int input()
{
	int number = 0;
	cout << "Enter an integer number, please:" << endl;
	cin >> number;
	return number;
}

int gcd(int firstNumber, int secondNumber) 
{
	if (firstNumber % secondNumber)
		gcd(secondNumber, firstNumber % secondNumber);
	else
		return secondNumber;
}

void swapFraction(int i, int j, int array[])
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}


void bubbleSort(int numenator[], int denominator[], int point) 
{
	bool ok = true;
	while (ok)
	{
		ok = false;
		for (int i = 0; i < point - 1; i++)
		{
			int first = numenator[i] * denominator[i+1];
			int second = numenator[i+1] * denominator[i];
			if (first > second)
			{
				ok = true;
				swapFraction(i, i+1, numenator);
				swapFraction(i, i+1, denominator);
			}	
		}
	}

}



void findFraction(int number)
{
	const int maxSize = 1000;

	int point = 0;
	int numenator[maxSize];
	int denominator[maxSize];

	for (int i = 2; i <= number; i++)
		for (int j = 1; j < i; j++)
			if (gcd(i, j) == 1)
			{
				numenator[point] = j;
				denominator[point] = i;
				point++;
			}

	bubbleSort(numenator, denominator, point);

	cout << "All fractions from 0 to 1 are:" << endl;
	for (int i = 0; i < point; i++)
		cout << numenator[i] << "/" << denominator[i] << endl; 
}




int main() {

	int number = input();

	findFraction(number);

	return 0;
}