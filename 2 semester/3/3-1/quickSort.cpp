#include "quickSort.h"


QuickSort::QuickSort()
{

}

void QuickSort::sort(int *array, int sizeOfArray)
{
    quickSort(array, 0, sizeOfArray - 1);
}

void QuickSort::quickSort(int *array, int left, int right)
{
    int middle = (left + right) / 2;
    int i = left;
    int j = right;
    while (i < j)
    {
        while (array[i] < array[middle])
            i++;
        while (array[j] > array[middle])
            j--;
        if (i <= j)
        {
            int temporary = array[i];
            array[i] = array[j];
            array[j] = temporary;
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(array, left, j);
    if (i < right)
        quickSort(array, i, right);
}
