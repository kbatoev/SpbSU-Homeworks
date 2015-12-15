#pragma once

#include <QMainWindow>
#include <QEvent>

#include "game.h"
#include "View/gameview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool event(QEvent *qEvent);

private:
    Ui::MainWindow *ui;
    GameView *gameView;
};

