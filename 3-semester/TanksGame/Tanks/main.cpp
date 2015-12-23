#include "mainwindow.h"
#include <QApplication>

#include <fstream>
#include <ostream>

#include "View/gameview.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    GameView *view = new GameView();
    a.installEventFilter(view);
    //MainWindow w;
    //w.show();


    //view.show();

    return a.exec();
}
