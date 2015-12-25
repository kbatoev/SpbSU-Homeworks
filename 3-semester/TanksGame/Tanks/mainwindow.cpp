#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    messageTransferTimer(new QTimer)
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
    delete messageTransferTimer;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (myMove)
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

    if (isServer)
    {
        setWindowTitle(tr("Server"));
        myMove = true;
        netConfiguration = new Server(this, ui->serverStatusLabel);
        ui->serverStatusLabel->setVisible(true);
    }
    else
    {
        setWindowTitle(tr("Client"));
        myMove = false;
        netConfiguration = new Client(this, ui->serverStatusLabel, ui->comboBox, ui->portLineEdit, ui->connectButton);

        ui->comboBox->setVisible(true);
        ui->portLineEdit->setVisible(true);
        ui->connectButton->setVisible(true);
    }
    connect(netConfiguration, SIGNAL(connected()), this, SLOT(startGame()));
    connect(netConfiguration, SIGNAL(received(QString)), this, SLOT(makeOpponentMove(QString)));

}

void MainWindow::startGame()
{
    if (isServer)
    {
        game = new Game();
        ui->serverStatusLabel->setVisible(false);
        ui->graphicsView->setScene(game->getScene());
        netConfiguration->sendMessage(game->collectLandscapeInformation());
    }
    else
    {
        ui->comboBox->setEnabled(false);
        ui->portLineEdit->setEnabled(false);
        ui->comboBox->setVisible(false);
        ui->portLineEdit->setVisible(false);
        ui->connectButton->setVisible(false);
        game = new Game(Game::makeVectorFromQString(netConfiguration->getReceivedMessage()));
        ui->graphicsView->setScene(game->getScene());
    }
    connect(game, SIGNAL(finishedMove()), this, SLOT(finishMove()));
    connect(messageTransferTimer, SIGNAL(timeout()), this, SLOT(sendMessage()));
    messageTransferTimer->start(msec);
}

void MainWindow::makeOpponentMove(QString message)
{
    game->setCurrentInformation(message);
}

void MainWindow::sendMessage()
{
    if (myMove)
    {
        QString message = game->collectCurrentInformation();
        netConfiguration->sendMessage(message);
    }
}

void MainWindow::finishMove()
{
    myMove = false;
}
