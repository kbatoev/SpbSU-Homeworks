#include "game.h"

Game::Game()
{
    scene = new QGraphicsScene();
    landscape = new Landscape();
    qreal x = 100;
    tankPointOnScene = landscape->getPointWithXCoordinate(x);
    tank = new Tank(tankPointOnScene);

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
    if (keyEvent->key() == Qt::Key_D)
    {
        QPointF point = landscape->getPointWithXCoordinate(tankPointOnScene.x() + tank->getSpeed());
        QPointF newPoint = point;
        point.setX(point.x() - tank->getCenter().x());
        point.setY(point.y() - tank->getCenter().y());
        tankPointOnScene = newPoint;
        tank->setPos(point);
    }
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

