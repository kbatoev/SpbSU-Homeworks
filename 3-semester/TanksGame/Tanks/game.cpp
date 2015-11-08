#include "game.h"

Game::Game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, widthOfFrame, heightOfFrame);
    landscape = new Landscape();
    tank1 = new Tank(100, 100);
    scene->addItem(landscape);
    scene->addItem(tank1);
    //landscape->setFlags(QGraphicsItem::ItemIsMovable);
    updater = new Updater();

    connect(updater, SIGNAL(doUpdate()), this, SLOT(update()));
    updater->execute();

}

Game::~Game()
{
    delete landscape;
    delete scene;
}

bool Game::event(QEvent *qEvent)
{
    if (qEvent->type() == QEvent::KeyPress)
    {
    }
    if (qEvent->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *event = dynamic_cast<QMouseEvent *>(qEvent);
        int x = event->pos().x();
        int y = event->pos().y();
        tank2 = new Tank(x, y);
        scene->addItem(tank2);
        scene->update();

        //scene->update(0, 0, 1000, 700);
    }

    return true;
}


QGraphicsScene *Game::getScene()
{
    return scene;
}

void Game::update()
{
    QList<QGraphicsItem* > listOfItems = scene->items();
    for (int i = 0; i < listOfItems.size(); i++)
    {
        listOfItems[i]->update();
        scene->update();
    }
    scene->update();
}

