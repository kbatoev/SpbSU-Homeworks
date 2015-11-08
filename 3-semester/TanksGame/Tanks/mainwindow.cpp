#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new Game();

    ui->graphicsView->setGeometry(0, 0, 1000, 700);
    ui->graphicsView->setScene(game->getScene());


    //ui->graphicsView->mapToScene(polygon);
    //ui->graphicsView->show();
    //ui->centralWidget->set
    //painter.drawPolygon(polygon);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}

bool MainWindow::event(QEvent *qEvent)
{
    if (qEvent->type() == QEvent::KeyPress || qEvent->type() == QEvent::MouseButtonPress)
        return game->event(qEvent);
}
