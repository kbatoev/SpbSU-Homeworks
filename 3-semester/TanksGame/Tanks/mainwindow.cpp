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
    ui->connectButton->setVisible(false);

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
    ui->serverStatusLabel->setVisible(true);
    if (isServer)
    {
        netConfiguration = new Server(this, ui->serverStatusLabel);
    }
    else
    {
        netConfiguration = new Client(this, ui->serverStatusLabel, ui->comboBox, ui->portLineEdit, ui->connectButton);
        ui->comboBox->setVisible(true);
        ui->portLineEdit->setVisible(true);
        ui->connectButton->setVisible(true);
    }
}

void MainWindow::startGame()
{
    if (isServer)
    {
        ui->serverStatusLabel->setVisible(false);
        ui->graphicsView->setScene(game->getScene());
    }
    else
    {

    }
}
