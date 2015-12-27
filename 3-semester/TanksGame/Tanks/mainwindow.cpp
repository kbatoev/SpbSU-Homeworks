#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(nullptr),
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
    if (myMove && game)
    {
        Keys key = determineKey(event);
        game->keyPressEvent(key);
    }
}

Keys MainWindow::determineKey(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A)
        return leftMove;
    if (event->key() == Qt::Key_D)
        return rightMove;
    if (event->key() == Qt::Key_S)
        return leftGun;
    if (event->key() == Qt::Key_W)
        return rightGun;
    if (event->key() == Qt::Key_Q)
        return changingBullet;
    if (event->key() == Qt::Key_Enter)
        return shot;
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
    //connect();

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

    connect(game, SIGNAL(finishedMove()), this, SLOT(changePlayer()));
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

void MainWindow::changePlayer()
{
    myMove = !myMove;
    game->setNextTank();
}

void MainWindow::moveRight()
{

}

void MainWindow::moveLeft()
{

}

void MainWindow::rotateGunRight()
{

}

void MainWindow::rotateGunLeft()
{

}
