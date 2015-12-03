#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->centralWidget->setVisible(false);
    gameView = new GameView(parent, new Game());
    //setCentralWidget(gameView->getQGraphicsView());
    //ui->centralWidget



    //ui->graphicsView->setGeometry(0, 0, 1000, 700);
    //ui->graphicsView->setScene(game->getScene());


    //ui->graphicsView->mapToScene(polygon);
    //ui->graphicsView->show();
    //ui->centralWidget->set
    //painter.drawPolygon(polygon);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gameView;
}

/*
void MainWindow::keyPressEvent(QKeyEvent *keyEvent)
{
    if (keyEvent->key() == 'a')
    {
        int qwer = 0;
    }
}
*/

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
