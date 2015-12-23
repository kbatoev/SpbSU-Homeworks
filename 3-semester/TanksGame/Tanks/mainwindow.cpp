#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(new Game)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(game->getScene());
    ui->graphicsView->setFocus();
    //ui->graphicsView->setVisible(false);
    //ui->descriptionLabel->setText(tr("Keys:\nA - go left; D - go right; W,S - change gun's angle;"
      //                               "Enter - make shot"));


}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    ui->graphicsView->setEnabled(false);
    game->keyPressEvent(event);
}
