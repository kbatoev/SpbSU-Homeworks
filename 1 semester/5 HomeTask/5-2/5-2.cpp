#include <iostream>

using namespace std;

double reverse(long long int summand)
{
	return(1.0) / double(summand);
}

int main()
{
	const int maxBit = 63;
	const int order = 10;
	const int bitsOfExponent = 11;
	const int bitsOfMantissa = 52;

	double number = 0;
	cout << "Enter any number, please:" << endl;
	cin >> number;

	long long int bits = *((long long int*) &number);

	long long int sign = 1;
	sign <<= 63;

	char mark = '+';
	if (sign & bits)
		mark = '-';

	int item = 1;
	item <<= order;
	int exponent = 1 - item;

	long long int currentBit = 1;
	currentBit <<= (maxBit - 1);

	for (int i = 0; i < bitsOfExponent; i++)
	{
		if (bits & currentBit)
			exponent += item;
		currentBit >>= 1;
		item >>= 1;
	}

	double mantissa = 1.0;
	long long int summand = 2;
	for (int i = 0; i < bitsOfMantissa; i++)
	{
		if (bits & currentBit)
			mantissa += reverse(summand);
		summand <<= 1;
		currentBit >>= 1;
	}

	cout << "This is exponential form of your number: " << endl;
	cout.precision(20);
	if (number == 0)
		cout << "0" << endl;
	else
		cout << mark << mantissa << "*2^(" << exponent << ")" << endl;

	return 0;
}