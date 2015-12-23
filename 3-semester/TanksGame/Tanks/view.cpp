#include "view.h"

View::View(QWidget *parent) :
    QMainWindow(parent)
{
    game = new Game(this);
    view = new QGraphicsView(game->getScene());
    setCentralWidget(view);
}

bool View::event(QEvent *event)
{
    int flag = 1;
    if (event->type() == QEvent::KeyPress)
    {
        int gg = 1;
        game->keyPressEvent(dynamic_cast<QKeyEvent *>(event));
        return true;
    }
}

