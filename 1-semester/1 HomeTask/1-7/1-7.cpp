#include <stdio.h>

int main() {

	const int first = 2;
	const int maxSize = 10000;
	bool array[maxSize];
	for (int i = 0; i < maxSize; i++)
		array[i] = true;

	int number = 0;
	printf("Enter number, that is more than 2 :\n");
	scanf("%d", &number);

	
	for (int i = first; i <= number; i++)
		if (array[i])
			for (int j = 2 * i; j <= number; j += i)
				array[j] = false;

	printf("All prime numbers from 2 to entered number are:\n");
	for (int i = first; i <= number; i++)
		if (array[i])
			printf("%d ", i);
	printf("\n");

	return 0;
}