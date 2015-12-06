#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gameView = new GameView(parent, new Game());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gameView;
}

bool MainWindow::event(QEvent *qEvent)
{
    if (qEvent->type() == QEvent::KeyPress)
    {
        gameView->keyPressEvent(dynamic_cast<QKeyEvent *>(qEvent));
        return true;
    }
    if(qEvent->type() == QEvent::KeyRelease)
    {
        gameView->keyReleaseEvent(dynamic_cast<QKeyEvent *>(qEvent));
        return true;
    }
}
