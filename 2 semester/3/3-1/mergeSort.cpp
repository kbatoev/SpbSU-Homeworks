#include "mergeSort.h"

MergeSort::MergeSort()
{
}

void MergeSort::sort(int* array, int sizeOfArray)
{
    int *sortedArray = mergeSort(array, 0, sizeOfArray - 1);
    for (int i = 0; i < sizeOfArray; i++)
        array[i] = sortedArray[i];
    delete[] sortedArray;
}


int* merge(int *firstHalf, int *secondHalf, int firstSize, int secondSize)
{
    int i = 0;
    int j = 0;
    int current = 0;

    int *newArray = new int[firstSize + secondSize];
    while (i < firstSize || j < secondSize)
    {
        if (i == firstSize)
        {
            newArray[current++] = secondHalf[j++];
        }
        else
        if (j == secondSize)
        {
            newArray[current++] = firstHalf[i++];
        }
        else
        {
            if (firstHalf[i] < secondHalf[j])
                newArray[current++] = firstHalf[i++];
            else
                newArray[current++] = secondHalf[j++];
        }
    }
    delete[] firstHalf;
    delete[] secondHalf;
    return newArray;
}


int* MergeSort::mergeSort(int *array, int first, int last)
{
    if (first != last)
    {
        int middle = (first + last) / 2;
        int *firstHalf = mergeSort(array, first, middle);
        int *secondHalf = mergeSort(array, middle + 1, last);
        int *result = merge(firstHalf, secondHalf, middle - first + 1, last - middle);
        return result;
    }
    else
    {
        int *newArray = new int[1];
        newArray[0] = array[first];
        return newArray;
    }
}
