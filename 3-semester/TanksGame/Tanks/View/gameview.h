#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QMainWindow>

#include "game.h"

/**
 * @brief The GameView class
 * the purpose is to create QGraphicsView from game->getScene()
 */

class GameView : public QWidget
{
public:
    explicit GameView(QWidget *parent, Game *newGame);
    ~GameView();

    /// delegates event to Game class
    void keyPressEvent(QKeyEvent *keyEvent);

private:
    Game *game;
    QGraphicsView *graphicsView;
};
