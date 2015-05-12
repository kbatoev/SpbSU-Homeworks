#include <iostream>

#include "vector.h"
#include "vectorTest.h"

int main()
{
    VectorTest test;
    QTest::qExec(&test);

    return 0;
}
