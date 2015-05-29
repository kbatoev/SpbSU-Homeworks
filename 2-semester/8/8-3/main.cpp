#include "xsAndOsUIi.h"
#include <QApplication>

#include "xoGameTest.h"

int main(int argc, char *argv[])
{
    XOGameTest test;
    QTest::qExec(&test);

    QApplication a(argc, argv);
    XsAndOsUI w;
    w.show();

    return a.exec();
}
