#pragma once

#include <QMainWindow>
#include <QEvent>

#include "game.h"
#include "Net/netconfiguration.h"
#include "Net/server.h"
#include "Net/client.h"

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

    void finishMove();


private:
    Ui::MainWindow *ui;
    Game *game;
    NetConfiguration *netConfiguration;

    bool isServer;
    bool myMove;
};

