#include "game.h"

Game::Game()
{
    scene = new QGraphicsScene();
    landscape = new Landscape();
    qreal x = 100;
    tankPointOnScene = landscape->getPointWithXCoordinate(x) + QPointF(0, -tank->getRadius());
    tank = new Tank(tankPointOnScene);

    keyController = new KeyController(tank, landscape, this);

    scene->setSceneRect(0, 0, widthOfFrame, heightOfFrame);
    scene->addItem(landscape);
    scene->addItem(tank);

    gameTimer = new QTimer();
    connect(gameTimer, SIGNAL(timeout()), this, SLOT(updateScene()));
    gameTimer->start(msec);
}

Game::~Game()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        delete bullets[i];
    }

    delete landscape;
    delete scene;
    delete keyController;
    delete gameTimer;
}

void Game::keyPressEvent(QKeyEvent *keyEvent)
{
    keyController->handleKey(keyEvent);
    updateScene();
}

void Game::keyReleaseEvent(QKeyEvent *keyEvent)
{

}

void Game::updateScene()
{
    /*
    QList<QGraphicsItem* > listOfItems = scene->items();
    for (int i = 0; i < listOfItems.size(); i++)
    {
        listOfItems[i]->update();
        scene->update();
    }
    */
    scene->update();
}

Landscape *Game::getLandscape() const
{
    return landscape;
}

QGraphicsScene *Game::getScene() const
{
    return scene;
}

void Game::addBullet(Bullet *newBullet)
{
    bullets.append(newBullet);
}

