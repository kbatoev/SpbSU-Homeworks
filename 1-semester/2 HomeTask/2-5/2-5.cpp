#include <iostream>

using namespace std;

void siftUp(int array[], int current) 
{
	int ancestor = (current - 1) / 2;
	while ((array[current] > array[ancestor]))
	{
		int temp = array[current];
		array[current] = array[ancestor];
		array[ancestor] = temp;
		current = ancestor;
		ancestor = (current - 1) / 2;
	}
}


void siftDown(int array[], int limit)
{
	int current = 0;
	int point = current;

	bool ok = true;
	while (ok)
	{
		ok = false;
		int first = current * 2 + 1;
		int second = current * 2 + 2;
		if (second < limit)
		{
			if (array[first] > array[second])
				point = first;
			else
				point = second;
		}
		else
		{
			if (first < limit)
				point = first;
		}

		if (array[current] < array[point])
		{
			int temp = array[point];
			array[point] = array[current];
			array[current] = temp;
			current = point;
			ok = true;
		}
		
	}

}


void heapSort(int array[], int number)
{
	const int top = 0;
	int current = number - 1;

	while (current > 0)
	{
		int temp = array[top];
		array[top] = array[current];
		array[current] = temp;
		siftDown(array, current);
		current--;
	}

}


int main() {

	const int maxSize = 1000;

	cout << "Enter a number, please:" << endl;
	int number = 0;
	cin >> number;

	cout << "Enter an array, please:" << endl;
	int array[maxSize];
	for (int i = 0; i < number; i++)
	{
		cin >> array[i];
		siftUp(array, i);
	}
	
	heapSort(array, number);

	cout << "Sorted sequence is :" << endl;
	for (int i = 0; i < number; i++)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}