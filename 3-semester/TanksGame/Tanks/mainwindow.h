#pragma once

#include <QMainWindow>
#include <QEvent>
#include <QTimer>

#include "game.h"
#include "Net/netconfiguration.h"
#include "Net/server.h"
#include "Net/client.h"
#include "Constants/constants.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 * Sets Widgets, gets key events, buttons events.
 */


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *event);

private slots:
    /// sets user's choice and connects Net Signals
    void setServer();
    void setClient();
    void startConnection();

    /// game starts after connecting with another application
    void startGame();

    /// receives state done in another application and sets it
    void makeOpponentMove(QString message);

    /// gets state and sends it to another app
    void sendMessage();

    /// color is used for determining tank
    void endGame(QColor colorOfLostTank);
    void updateLabels(int health, QColor color);

    void changePlayer();
    void moveRight();
    void moveLeft();
    void rotateGunRight();
    void rotateGunLeft();
    void changeBullet();
    void shoot();


    void enableGameButtons(bool mode);
    void setInvisibleNetworkWidgets();


private:
    Ui::MainWindow *ui;
    Game *game;
    NetConfiguration *netConfiguration;
    QTimer *messageTransferTimer;

    bool isServer;
    bool myMove;
};

