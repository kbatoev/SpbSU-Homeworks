#include <iostream>
#include "list.h"
#include "listTest.h"

int main()
{
    ListTest test;
    QTest::qExec(&test);


    return 0;
}
