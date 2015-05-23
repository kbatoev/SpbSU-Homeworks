#include <iostream>
#include "linkedList.h"
#include "comparable.h"
#include "sortedSet.h"

#include "comparableTest.h"

int main()
{
    ComparableTest test;
    QTest::qExec(&test);

    return 0;
}

