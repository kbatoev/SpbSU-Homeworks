#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QMainWindow>
#include <QGridLayout>

#include "game.h"

/**
 * @brief The GameView class
 * the purpose is to create QGraphicsView from game->getScene()
 */

class GameView : public QWidget
{
public:
    GameView(QWidget *parent, Game *newGame);
    GameView();
    ~GameView();

    /// delegates event to Game class
    void keyPressEvent(QKeyEvent *keyEvent);
    bool event(QEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);

private:
    Game *game;
    QGraphicsView *graphicsView;
    QGridLayout *gridLayout;
};
