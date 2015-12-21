#include "gameview.h"

GameView::GameView(QWidget *widget) :
    QMainWindow(widget)
{
    //game = new Game;
    //graphicsView = new QGraphicsView(game->getScene());
    //setCentralWidget(graphicsView);
    //graphicsView->show();
}

GameView::~GameView()
{
    delete game;
    delete graphicsView;
}

//void GameView::keyPressEvent(QKeyEvent *keyEvent)
//{
//    game->keyPressEvent(keyEvent);
//}

//bool GameView::event(QEvent *event)
//{
//    int flag = 0;
//    if (event->type() == QEvent::KeyPress)
//    {
//        int flag2 = 0;
//    }
//}

//QGraphicsView *GameView::getGraphicsView() const
//{
//    return graphicsView;
//}
