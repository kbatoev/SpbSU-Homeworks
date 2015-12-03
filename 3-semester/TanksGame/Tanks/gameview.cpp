#include "gameview.h"

GameView::GameView(QWidget *parent, Game *newGame) :
    QWidget(parent)
{
    game = newGame;
    graphicsView = new QGraphicsView(game->getScene());
    graphicsView->show();
    //QEvent::accept(Qt::Ke)
}

void GameView::keyPressEvent(QKeyEvent *keyEvent)
{
    game->keyPressEvent(keyEvent);
}

void GameView::keyReleaseEvent(QKeyEvent *keyEvent)
{
    game->keyReleaseEvent(keyEvent);
}

QGraphicsView *GameView::getQGraphicsView()
{
    return graphicsView;
}

