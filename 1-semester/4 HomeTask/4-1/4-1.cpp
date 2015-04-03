#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void quickSort(int first, int last, int *array)
{
	int randomPlace = rand() % (last + 1);
	int supportElement = array[randomPlace];

	int left = first;
	int right = last;

	while (left < right)
	{
		while (supportElement > array[left])
			left++;
		while (supportElement < array[right])
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

int main()
{
	cout << "Enter an size of array, please:" << endl;
	int number = 0;
	cin >> number;

	int *array = new int[number];

	cout << "Enter elements of array:" << endl;
	for (int i = 0; i < number; i++)
		cin >> array[i];

	int first = 0;
	int last = number - 1;

	srand(time(NULL));
	quickSort(first, last, array);

	bool isFound = false;
	int current = last - 1;
	int maximum = 0;
	while (current >= 0 && !isFound)
	{
		if (array[current] == array[current + 1])
		{
			isFound = true;
			maximum = array[current];
		}
		current--;
	}

	if (isFound)
		cout << "Maximum is " << maximum << endl;
	else
		cout << "There's no maximum element, that is found more than once" << endl;

	delete[] array;
	
	return 0;
}