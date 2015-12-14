#include "gameview.h"

GameView::GameView(QWidget *parent, Game *newGame) :
    QWidget(parent)
{
    game = newGame;
    graphicsView = new QGraphicsView(game->getScene());
    graphicsView->show();
}

GameView::~GameView()
{
    delete game;
    delete graphicsView;
}

void GameView::keyPressEvent(QKeyEvent *keyEvent)
{
    game->keyPressEvent(keyEvent);
}

void GameView::keyReleaseEvent(QKeyEvent *keyEvent)
{
    game->keyReleaseEvent(keyEvent);
}

