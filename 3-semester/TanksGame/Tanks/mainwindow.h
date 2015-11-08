#pragma once

#include <QMainWindow>
#include <QEvent>

#include "game.h"

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
    //bool eventFilter(QObject *qObject, QEvent *qEvent);

private:
    Ui::MainWindow *ui;
    Game *game;
};

