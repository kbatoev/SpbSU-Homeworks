#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(new Game)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(game->getScene());


}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    game->keyPressEvent(event);
}
