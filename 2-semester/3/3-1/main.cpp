#include <iostream>
#include "quickSort.h"
#include "mergeSort.h"
#include "heapSort.h"

using namespace std;

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
        cin >> array[i];

    QuickSort qSort;
    //qSort.sort(array, 10);

    MergeSort mSort;
    //mSort.sort(array, 10);

    HeapSort hSort;
    hSort.sort(array, 10);

    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";

    return 0;
}

