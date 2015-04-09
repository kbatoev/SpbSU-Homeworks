#include <iostream>
#include "matrix.h"
#include "consolePrinter.h"
#include "filePrinter.h"

#include "matrixTest.h"

int main()
{
    MatrixTest test;
    QTest::qExec(&test);

    return 0;
}

