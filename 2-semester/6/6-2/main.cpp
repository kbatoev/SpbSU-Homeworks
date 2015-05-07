#include <iostream>
#include "set.h"
#include "setTest.h"

int main()
{
    SetTest test;
    QTest::qExec(&test);

    return 0;
}
