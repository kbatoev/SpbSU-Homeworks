#include <iostream>

#include "bagTest.h"
#include "bag.h"
#include "avlTree.h"

int main()
{
    BagTest test;
    QTest::qExec(&test);

    return 0;
}
