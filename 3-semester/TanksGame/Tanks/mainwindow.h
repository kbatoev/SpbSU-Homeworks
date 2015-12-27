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
 */


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *event);

private slots:
    void setServer();
    void setClient();

    void startConnection();
    void startGame();
    void endGame(QColor color);
    void makeOpponentMove(QString message);
    void updateLabels(int health, QColor color);
    void sendMessage();

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

