#include "mainwindow.h"
#include <QApplication>

#include <fstream>
#include <ostream>

#include "View/gameview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.installEventFilter();
    //MainWindow w;
    //w.show();

    GameView view;
    view.show();

    return a.exec();
}
