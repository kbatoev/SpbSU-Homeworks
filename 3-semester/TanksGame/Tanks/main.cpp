#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>

//#include "View/gameview.h"

#include "view.h"

#include <fstream>
#include <ostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //GameView gameView;
    //gameView.show();
//    QMainWindow mainWindow;
//    mainWindow.setCentralWidget(gameView);
//    mainWindow.show();
    View v;
    v.show();


    return a.exec();
}
