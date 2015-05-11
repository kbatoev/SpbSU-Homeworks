#include <iostream>

#include "vector.h"
#include "vectortest.h"

int main()
{
    VectorTest test;
    QTest::qExec(&test);

    return 0;
}
