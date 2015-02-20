#include <stdio.h>


void quickSort(int first, int last, int* array) {

	int left = first;
	int right = last;
	int midElement = array[(left + right) / 2];

	while (left < right)
	{
		while (array[left] < midElement)
			left++;
		while (array[right] > midElement)
			right--;
		if (left <= right)
		{
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}

	}

	if (first < right)
		quickSort(first, right, array);
	if (left < last)
		quickSort(left, last, array);
}


int main() {

	const int maxSize = 10000;

	int array[maxSize];
	printf("Enter a number:\n");
	int number = 0;
	scanf("%d", &number);

	printf("Enter a sequence of %d elements:\n", number);
	for (int i = 0; i < number; i++)
		scanf("%d", array + i);

	int left = 0;
	int right = number - 1;

	quickSort(left, right, array);

	printf("Sorted sequence is:\n");
	for (int i = 0; i < number; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}