#include "xsAndOsUIi.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XsAndOsUI w;
    w.show();

    return a.exec();
}
