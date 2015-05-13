#include <iostream>
#include "smartPointerTest.h"

int main()
{
    SmartPointerTest test;
    QTest::qExec(&test);

    return 0;
}
