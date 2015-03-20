#include <iostream>
#include "quickSort.h"
#include "mergeSort.h"
#include "heapSort.h"

using namespace std;

int main()
{
    int size = 0;
    cout << "Enter a size of array: ";
    cin >> size;

    int *array = new int[size];

    cout << "Enter an array: " << endl;
    for (int i = 0; i < size; i++)
        cin >> array[i];

    QuickSort qSort;
    //qSort.sort(array, size);

    MergeSort mSort;
    mSort.sort(array, size);

    HeapSort hSort;
    //hSort.sort(array, size);


    cout << "Sorted array is: " << endl;
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";

    return 0;
}

