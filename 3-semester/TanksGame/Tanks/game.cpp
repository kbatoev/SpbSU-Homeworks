#include "game.h"

Game::Game()
{
    scene = new QGraphicsScene();
    landscape = new Landscape();

    createTank(startXCoordinate1, Qt::blue);
    createTank(startXCoordinate2, Qt::red);

    setCurrentTank(0);

    keyController = new KeyController(this);

    scene->setSceneRect(0, 0, widthOfFrame, heightOfFrame);
    scene->addItem(landscape);

    for (int i = 0; i < tanks.size(); i++)
    {
        scene->addItem(tanks[i]);
    }

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
    for (int i = 0; i < bursts.size(); i++)
    {
        delete bursts[i];
    }

    for (int i = 0; i < tanks.size(); i++)
    {
        delete tanks[i];
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

void Game::updateScene()
{
    QList<QGraphicsItem* > listOfItems = scene->items();
    QList<QRectF > rects;
    for (int i = 0; i < listOfItems.size(); i++)
    {
        rects.append(listOfItems[i]->boundingRect());
    }

    for (int i = 0; i < rects.size(); i++)
    {
        for (int j = i + 1; j < rects.size(); j++)
        {
            if (rects[i].intersects(rects[j]))
            {
                Burstable *firstItem = dynamic_cast<Burstable *>(listOfItems[i]);
                Burstable *secondItem = dynamic_cast<Burstable *>(listOfItems[j]);

                if (firstItem)
                {
                    firstItem->drawBurst(secondItem);
                }
                if (secondItem)
                {
                    secondItem->drawBurst(firstItem);
                }
            }
        }
    }


    for (int i = 0; i < listOfItems.size(); i++)
    {
        QRectF rect = listOfItems[i]->boundingRect();
        listOfItems[i]->update();
        scene->update();
    }
    scene->update();
}

Tank *Game::getCurrentTank() const
{
    return tanks[currentTankNumber];
}

void Game::setCurrentTank(int number)
{
    currentTankNumber = number;
}

void Game::setNextTank()
{
    ++currentTankNumber %= tanks.size();
}

void Game::createTank(int xcoordinate, QColor color)
{
    tankPointOnScene = landscape->getPointWithXCoordinate(xcoordinate) + QPointF(0, -Tank::getRadius());
    tanks.append(new Tank(tankPointOnScene, color));
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

void Game::addBurst(Burst *newBurst)
{
    bursts.append(newBurst);
}

