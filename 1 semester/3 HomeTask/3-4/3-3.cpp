#include <iostream>

using namespace std;

int main()
{
	const int maxDigit = 10;

	int figures[maxDigit];
	for (int i = 0; i < maxDigit; i++)
		figures[i] = 0;

	int number = 0;
	cout << "Enter a number, please:" << endl;
	cin >> number;

	int minDigit = 9;
	while (number > 0)
	{
		int digit = number % 10;

		if (digit < minDigit && digit > 0)
			minDigit = digit;

		figures[digit]++;

		number /= 10; 
	}
	
	cout << "Minimal number is:" << endl;

	cout << minDigit;
	figures[minDigit]--;

	for (int i = 0; i < maxDigit; i++)
	{
		while (figures[i] > 0)
		{
			cout << i;
			figures[i]--;
		}
	}

	cout << endl;

	return 0;
}