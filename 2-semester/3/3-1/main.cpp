#include <iostream>
#include "quickSort.h"
#include "mergeSort.h"
#include "heapSort.h"

#include "quickSortTest.h"
#include "mergeSortTest.h"
#include "heapSortTest.h"


int main()
{
    QuickSortTest quickSortTest;
    QTest::qExec(&quickSortTest);

    std::cout << "\n\n";
    MergeSortTest mergeSortTest;
    QTest::qExec(&mergeSortTest);

    std::cout << "\n\n";
    HeapSortTest heapSortTest;
    QTest::qExec(&heapSortTest);

    return 0;
}

