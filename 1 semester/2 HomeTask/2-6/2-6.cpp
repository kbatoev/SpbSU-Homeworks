#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


int main()
{
	const int maxNumber = 9;
	const int rank = 4;

	bool used[maxNumber];
	for (int i = 0; i < maxNumber; i++)
		used[i] = false;

	int chosenNumber[rank];
	int count = 0;
	while (count < rank)
	{
		srand(time(0));
		int value = rand() % maxNumber + 1;
		if (!used[value - 1])
		{
			chosenNumber[count] = value;
			count++;
			used[value - 1] = true;
		}
	}
	
	cout << "I've chosen a number, and you have to find it. Let's start" << endl;

	bool ok = false;
	while (!ok)
	{
		int number = 0;
		cout << "Enter a number:" << endl;
		cin >> number;
		
		int enteredNumber[rank];
		int point = 0;
		while (number)
		{
			enteredNumber[point++] = number % 10;
			number /= 10;
		}

		int bulls = 0;
		int cows = 0;
		for (int i = 0; i < rank; i++)
			for (int j = 0; j < rank; j++)
				if (enteredNumber[i] == chosenNumber[j])
					if (i == j)
						bulls++;
					else
						cows++;

		cout << bulls << " bulls " << cows << " cows" << endl;
		if (bulls == rank)
			ok = true;
	}

	cout << "Excellent! You've done it!" << endl;

	return 0;
}