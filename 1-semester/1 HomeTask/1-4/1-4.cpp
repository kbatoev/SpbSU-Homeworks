#include <stdio.h>

int main() {

	const int maxNumber = 9;
	const int maxSize = 28;

	int mas[maxSize];
	for (int i = 0; i < maxSize; i++)
		mas[i] = 0;

	for (int i = 0; i <= maxNumber; i++)
		for (int j = 0; j <= maxNumber; j++)
			for (int k = 0; k <= maxNumber; k++)
			{
				int sum = i + j + k;
				mas[sum]++;
			}

	int answer = 0;
	for (int i = 0; i < maxSize; i++)
	{
		mas[i] *= mas[i];
		answer += mas[i];
	}

	printf("There are %d happy tickets\n", answer);

	return 0;
}