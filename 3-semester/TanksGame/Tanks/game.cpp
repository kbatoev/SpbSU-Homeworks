#include "game.h"

Game::Game(QVector<QPointF> *serverPoints)
{
    scene = new QGraphicsScene();
    landscape = new Landscape(serverPoints);
    hasShot = false;

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

QVector<QPointF> *Game::makeVectorFromQString(QString message)
{
    return Landscape::makeVectorFromQString(message);
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
    hasShot = false;
}

void Game::setNextTank()
{
    ++currentTankNumber %= tanks.size();
}

QString Game::collectLandscapeInformation()
{
    QString information = "";
    information += QString::number(landscape->getNumberPoints()) + separator;
    QVector<QPointF> *points = landscape->getPoints();
    for (int i = 0; i < points->size(); i++)
    {
        information += QString::number(points->at(i).x()) + separator;
        information += QString::number(points->at(i).y()) + separator;
    }
    return information;
}

QString Game::collectCurrentInformation()
{
    QString result = "";
    Tank *currentTank = getCurrentTank();
    QPointF center = currentTank->getCenter();
    result += QString::number(center.x()) + separator;
    result += QString::number(center.y()) + separator;
    qreal angle = currentTank->getGunAngle();
    result += QString::number(angle) + separator;
    result += QString::number(hasShot) + separator;
    if (hasShot)
        emit finishedMove();

    return result;
}

void Game::setCurrentInformation(QString message)
{
    Tank *currentTank = getCurrentTank();
    int index = 0;
    qreal x = Landscape::readUntilSeparator(message, index).toFloat();
    qreal y = Landscape::readUntilSeparator(message, ++index).toFloat();
    qreal angle = Landscape::readUntilSeparator(message, ++index).toFloat();
    qreal shot = Landscape::readUntilSeparator(message, ++index).toFloat();
    currentTank->setCenter(QPointF(x, y));
    currentTank->setGunAngle(angle);
    if (shot)
    {
        currentTank->shoot();
        emit finishedMove();
    }
}

void Game::currentTankShot()
{
    hasShot = true;
}


void Game::createTank(int xcoordinate, QColor color)
{
    tankPointOnScene = landscape->getPointWithXCoordinate(xcoordinate) + QPointF(0, -Tank::getRadius());
    tanks.append(new Tank(this, tankPointOnScene, color));
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

