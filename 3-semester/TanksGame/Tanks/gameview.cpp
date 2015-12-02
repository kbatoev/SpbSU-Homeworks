#include "gameview.h"

GameView::GameView(QWidget *parent, Game *newGame) :
    QWidget(parent)
{
    game = newGame;
    graphicsView = new QGraphicsView(game->getScene());
    graphicsView->show();
}

void GameView::keyPressEvent(QKeyEvent *keyEvent)
{
    game->keyPressEvent(keyEvent);
}

QGraphicsView *GameView::getQGraphicsView()
{
    return graphicsView;
}

