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
    void makeOpponentMove(QString message);
    void sendMessage();

    void changePlayer();


private:
    Ui::MainWindow *ui;
    Game *game;
    NetConfiguration *netConfiguration;

    bool isServer;
    bool myMove;

    QTimer *messageTransferTimer;
};

