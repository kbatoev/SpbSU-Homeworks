#include "mainwindow.h"
#include <QApplication>

#include <fstream>
#include <ostream>

int main(int argc, char *argv[])
{
    std::ofstream out;
    out.open("test");
    out << "hi";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
