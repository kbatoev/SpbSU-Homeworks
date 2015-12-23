#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(new Game)
{
    ui->setupUi(this);
    connect(ui->serverRadio, SIGNAL(clicked(bool)), this, SLOT(setServer()));
    connect(ui->clientRadio, SIGNAL(clicked(bool)), this, SLOT(setClient()));

    ui->graphicsView->setFocus();
    ui->comboBox->setVisible(false);
    ui->portLineEdit->setVisible(false);
    ui->serverStatusLabel->setVisible(false);
    //ui->graphicsView->setScene(game->getScene());

    //ui->graphicsView->setVisible(false);
    //ui->descriptionLabel->setText(tr("Keys:\nA - go left; D - go right; W,S - change gun's angle;"
      //                               "Enter - make shot"));

    //connect(ui->radioButton, SIGNAL(clicked(bool)), this, SLOT(makeInvisible()));

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

void MainWindow::makeInvisible()
{
    //ui->radioButton->setVisible(false);
}

void MainWindow::setServer()
{
    isServer = true;
    startConnection();
}

void MainWindow::setClient()
{
    isServer = false;
    startConnection();
}

void MainWindow::startConnection()
{
    ui->serverRadio->setVisible(false);
    ui->clientRadio->setVisible(false);
    ui->serverStatusLabel->setVisible(false);
}
