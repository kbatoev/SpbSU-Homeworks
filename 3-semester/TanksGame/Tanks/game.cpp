#include "game.h"

Game::Game()
{
    scene = new QGraphicsScene();
    landscape = new Landscape();
    qreal x = 100;
    QPointF center = landscape->getPointWithXCoordinate(x);
    tank = new Tank(center);

    keyController = new KeyController(tank, landscape);

    scene->setSceneRect(0, 0, widthOfFrame, heightOfFrame);
    scene->addItem(landscape);
    scene->addItem(tank);
}

Game::~Game()
{
    delete landscape;
    delete scene;
}

QGraphicsScene *Game::getScene()
{
    return scene;
}

void Game::keyPressEvent(QKeyEvent *keyEvent)
{
    QPointF point = tank->pos();
    keyController->handleKey(keyEvent);
}

void Game::keyReleaseEvent(QKeyEvent *keyEvent)
{
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

