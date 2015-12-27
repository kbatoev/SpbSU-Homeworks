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

    setInvisibleNetworkWidgets();
    ui->redTankLabel->setVisible(false);
    ui->blueTankLabel->setVisible(false);
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
        if (event->key() == Qt::Key_A)
            moveLeft();
        if (event->key() == Qt::Key_D)
            moveRight();
        if (event->key() == Qt::Key_S)
            rotateGunLeft();
        if (event->key() == Qt::Key_W)
            rotateGunRight();
        if (event->key() == Qt::Key_Q)
            changeBullet();
        if (event->key() == Qt::Key_Enter)
            shoot();
    }
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
    setInvisibleNetworkWidgets();
    if (isServer)
    {
        game = new Game();
        enableGameButtons(true);
        ui->graphicsView->setScene(game->getScene());
        netConfiguration->sendMessage(game->collectLandscapeInformation());
    }
    else
    {
        game = new Game(Game::makeVectorFromQString(netConfiguration->getReceivedMessage()));
        enableGameButtons(false);
        ui->graphicsView->setScene(game->getScene());
    }

    connect(ui->leftMoveButton, SIGNAL(clicked(bool)), this, SLOT(moveLeft()));
    connect(ui->rightMoveButton, SIGNAL(clicked(bool)), this, SLOT(moveRight()));
    connect(ui->leftGunButton, SIGNAL(clicked(bool)), this, SLOT(rotateGunLeft()));
    connect(ui->rightGunButton, SIGNAL(clicked(bool)), this, SLOT(rotateGunRight()));
    connect(ui->changeBulletButton, SIGNAL(clicked(bool)), this, SLOT(changeBullet()));
    connect(ui->shotButton, SIGNAL(clicked(bool)), this, SLOT(shoot()));
    ui->bulletTypeLabel->setText(game->getBulletName());

    ui->redTankLabel->setVisible(true);
    ui->redTankLabel->setText(tr("Red Tank HitPoints: %1").arg(QString::number(initialHitPoints)));
    ui->blueTankLabel->setVisible(true);
    ui->blueTankLabel->setText(tr("Blue Tank HitPoints: %1").arg(QString::number(initialHitPoints)));

    connect(game, SIGNAL(finishedMove()), this, SLOT(changePlayer()));
    connect(game, SIGNAL(changedHealth(int, QColor)), this, SLOT(updateLabels(int, QColor)));
    connect(game, SIGNAL(gameIsOver(QColor)), this, SLOT(endGame(QColor)));
    connect(messageTransferTimer, SIGNAL(timeout()), this, SLOT(sendMessage()));
    messageTransferTimer->start(msec);
}

void MainWindow::endGame(QColor color)
{
    QMessageBox msgBox;
    if (color == Qt::red && isServer || color == Qt::blue && !isServer)
        msgBox.setText(tr("You are winner!"));
    else
        msgBox.setText(tr("You lost :("));

    msgBox.setWindowTitle(isServer? "Server" : "Client");
    messageTransferTimer->start(msec);
    myMove = false;
    enableGameButtons(false);
    msgBox.exec();
}

void MainWindow::makeOpponentMove(QString message)
{
    game->setCurrentInformation(message);
}

void MainWindow::updateLabels(int health, QColor color)
{
    if (health < 0)
        health = 0;

    if (color == Qt::blue)
        ui->blueTankLabel->setText(tr("Blue Tank HitPoints: %1").arg(QString::number(health)));
    else
        ui->redTankLabel->setText(tr("Red Tank HitPoints: %1").arg(QString::number(health)));
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
    enableGameButtons(myMove);
}

void MainWindow::moveRight()
{
    game->keyPressEvent(rightMove);
}

void MainWindow::moveLeft()
{
    game->keyPressEvent(leftMove);
}

void MainWindow::rotateGunRight()
{
    game->keyPressEvent(rightGun);
}

void MainWindow::rotateGunLeft()
{
    game->keyPressEvent(leftGun);
}

void MainWindow::changeBullet()
{
    game->keyPressEvent(changingBullet);
    ui->bulletTypeLabel->setText(game->getBulletName());
}

void MainWindow::shoot()
{
    game->keyPressEvent(shot);
}

void MainWindow::enableGameButtons(bool mode)
{
    ui->leftMoveButton->setEnabled(mode);
    ui->rightMoveButton->setEnabled(mode);
    ui->leftGunButton->setEnabled(mode);
    ui->rightGunButton->setEnabled(mode);
    ui->shotButton->setEnabled(mode);
    ui->changeBulletButton->setEnabled(mode);
}

void MainWindow::setInvisibleNetworkWidgets()
{
    ui->comboBox->setVisible(false);
    ui->portLineEdit->setVisible(false);
    ui->serverStatusLabel->setVisible(false);
    ui->connectButton->setVisible(false);
}

