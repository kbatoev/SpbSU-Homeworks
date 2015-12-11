#include "game.h"

Game::Game()
{
    scene = new QGraphicsScene();
    landscape = new Landscape();
    qreal x = 100;
    tankPointOnScene = landscape->getPointWithXCoordinate(x) + QPointF(0, -tank->getRadius());
    tank = new Tank(tankPointOnScene);

    keyController = new KeyController(tank, landscape);

    scene->setSceneRect(0, 0, widthOfFrame, heightOfFrame);
    scene->addItem(landscape);
    scene->addItem(tank);

    gameTimer = new QTimer();
    connect(gameTimer, SIGNAL(timeout()), this, SLOT(updateScene()));
    gameTimer->start(30);
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
    keyController->handleKey(keyEvent);
    if (keyEvent->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet(tank->getCenter(), tank->getGunAngleInRadians(), landscape);
        scene->addItem(bullet);
        bullet->fly();
    }

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
