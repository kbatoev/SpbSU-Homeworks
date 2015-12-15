#pragma once

#include <QMainWindow>
#include <QEvent>

#include "game.h"
#include "View/gameview.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 * The purpose of this class - to catch events
 */


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /// catches event and sends it to GameView
    bool event(QEvent *qEvent);

private:
    Ui::MainWindow *ui;
    GameView *gameView;
};

