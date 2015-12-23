#include "gameview.h"

GameView::GameView(QWidget *parent, Game *newGame) :
    QWidget(parent)
{
    game = newGame;
    graphicsView = new QGraphicsView(game->getScene());
    //graphicsView->show();
    //gridLayout = new QGridLayout;
    //gridLayout->addWidget(graphicsView, 0, 0, 5, 5);
    //this->setLayout(gridLayout);
    //this->show();
    graphicsView->show();
}

GameView::GameView()
{
    game = new Game();
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

bool GameView::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        int success = 1;
    }
}

bool GameView::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        int success = 1;
        game->keyPressEvent(dynamic_cast<QKeyEvent *>(event));
    }
}
