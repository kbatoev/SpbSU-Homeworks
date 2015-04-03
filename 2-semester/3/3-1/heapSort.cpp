#include "heapSort.h"

HeapSort::HeapSort()
{
}

void HeapSort::sort(int *array, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        siftUp(array, i);
    }
    heapSort(array, sizeOfArray);
}

void HeapSort::siftUp(int *array, int current)
{
    int ancestor = (current - 1) / 2;
    while (array[current] > array[ancestor])
    {
        int temporary = array[current];
        array[current] = array[ancestor];
        array[ancestor] = temporary;
        current = ancestor;
        ancestor = (current - 1) / 2;
    }
}

void HeapSort::siftDown(int *array, int limit)
{
    int current = 0;
    int point = current;

    bool canBeSiftedDown = true;
    while (canBeSiftedDown)
    {
        canBeSiftedDown = false;
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
        if (first < limit)
            point = first;

        if (array[current] < array[point])
        {
            int temporary = array[point];
            array[point] = array[current];
            array[current] = temporary;
            current = point;
            canBeSiftedDown = true;
        }

    }
}

void HeapSort::heapSort(int *array, int sizeOfArray)
{
    const int top = 0;
    int current = sizeOfArray - 1;

    while (current > 0)
    {
        int temporary = array[top];
        array[top] = array[current];
        array[current] = temporary;
        siftDown(array, current);
        current--;
    }
}
