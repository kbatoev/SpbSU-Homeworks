#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QMainWindow>

#include "game.h"

class GameView : public QWidget
{
public:
    explicit GameView(QWidget *parent, Game *newGame);

    void keyPressEvent(QKeyEvent *keyEvent);
    void keyReleaseEvent(QKeyEvent *keyEvent);

private:
    Game *game;
    QGraphicsView *graphicsView;
};
