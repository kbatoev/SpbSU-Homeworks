#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QMainWindow>

#include "game.h"

class GameView : public QWidget
{
public:
    explicit GameView(QWidget *parent, Game *newGame);
    ~GameView();

    void keyPressEvent(QKeyEvent *keyEvent);

private:
    Game *game;
    QGraphicsView *graphicsView;
};
