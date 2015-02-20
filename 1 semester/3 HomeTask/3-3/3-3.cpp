#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{

	srand(time(NULL));

	const int sides = 4;
	const int maxSize = 100;

	int array[maxSize][maxSize];
	int iSteps[4] = {1, 0, -1, 0};
	int jSteps[4] = {0, -1, 0, 1};

	cout << "Enter a number, please:" << endl;
	int number = 0;
	cin >> number;
	cout << "I've generated this matrix:" << endl;
	for (int i = 0; i < number; i++) 
	{
		for (int j = 0; j < number; j++)
		{
			array[i][j] = rand() % 10;
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

	int curI = number / 2;
	int curJ = number / 2;

	cout << "Elements coming in spiral are:" << endl;

	cout << array[curI][curJ] << " ";

	int step = 2;
	for (int i = 0; i < number/2; i++)
	{
		for (int j = 0; j < sides; j++)
			for (int k = 0; k < step; k++)
			{
				if (j == 0 && k == 0)
					curJ++;
				else
				{
					curI += iSteps[j];
					curJ += jSteps[j];
				}
				cout << array[curI][curJ] << " ";
			}
		 step += 2;
	}

	cout << endl;

	return 0;
}