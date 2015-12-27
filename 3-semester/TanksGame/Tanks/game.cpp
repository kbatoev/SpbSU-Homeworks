#include "game.h"

Game::Game(QVector<QPointF> *serverPoints)
{
    scene = new QGraphicsScene();
    landscape = new Landscape(serverPoints);
    hasShot = false;

    createTank(startXCoordinate1, Qt::blue);
    createTank(startXCoordinate2, Qt::red);

    setCurrentTank(0);

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
    for (int i = 0; i < tanks.size(); i++)
        delete tanks[i];

    delete landscape;
    delete scene;
    delete gameTimer;
}

QVector<QPointF> *Game::makeVectorFromQString(QString message)
{
    QVector<QPointF> *resultPoints = new QVector<QPointF>;
    int currentIndex = 0;
    int size = readUntilSeparator(message, currentIndex).toInt();
    for (int i = 0; i < size; i++)
    {
        float x = readUntilSeparator(message, ++currentIndex).toFloat();
        float y = readUntilSeparator(message, ++currentIndex).toFloat();
        resultPoints->append(QPointF(x, y));
    }
    return resultPoints;
}

QString Game::readUntilSeparator(QString message, int &startIndex)
{
    QString result = "";
    while (message.at(startIndex) != separator)
    {
        result.append(message.at(startIndex++));
    }
    return result;
}

void Game::keyPressEvent(Keys key)
{
    Tank *tank = getCurrentTank();
    QPointF oldPoint = tank->getCenter();
    QPointF point = oldPoint;

    switch (key)
    {
    case leftMove:
        point = landscape->getPointWithXCoordinate(oldPoint.x() - tank->getSpeed());
        point.setY(point.y() - tank->getRadius());
        if (point.x() > 0 && point.x() < widthOfFrame && point.y() > 0 && point.y() < heightOfFrame)
            tank->setCenter(point);
        break;

    case rightMove:
        point = landscape->getPointWithXCoordinate(oldPoint.x() + tank->getSpeed());
        point.setY(point.y() - tank->getRadius());
        if (point.x() > 0 && point.x() < widthOfFrame && point.y() > 0 && point.y() < heightOfFrame)
            tank->setCenter(point);
        break;

    case leftGun:
        tank->increaseAngle();
        break;

    case rightGun:
        tank->decreaseAngle();
        break;

    case changingBullet:
        tank->changeBullet();
        break;

    case shot:
        tank->shoot();
        currentTankShot();
        break;

    default:
        break;
    }
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
                Contactable *firstItem = dynamic_cast<Contactable *>(listOfItems[i]);
                Contactable *secondItem = dynamic_cast<Contactable *>(listOfItems[j]);

                if (firstItem && secondItem)
                {
                    firstItem->isContactedBy(secondItem);
                    secondItem->isContactedBy(firstItem);
                }
            }
        }
    }


    for (int i = 0; i < listOfItems.size(); i++)
    {
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
    hasShot = false;
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
    result += QString::number(currentTank->getGunAngle()) + separator;
    result += QString::number(currentTank->getBulletType()) + separator;
    result += QString::number(hasShot) + separator;

    if (hasShot)
    {
        emit finishedMove();
    }

    return result;
}

void Game::setCurrentInformation(QString message)
{
    Tank *currentTank = getCurrentTank();
    int index = 0;
    qreal x = readUntilSeparator(message, index).toFloat();
    qreal y = readUntilSeparator(message, ++index).toFloat();
    qreal angle = readUntilSeparator(message, ++index).toFloat();
    int bulletType = readUntilSeparator(message, ++index).toInt();
    hasShot  = readUntilSeparator(message, ++index).toFloat();
    currentTank->setCenter(QPointF(x, y));
    currentTank->setGunAngle(angle);
    currentTank->setBulletType(bulletType);

    if (hasShot)
    {
        currentTank->shoot();
        emit finishedMove();
    }
}

void Game::currentTankShot()
{
    hasShot = true;
}

QString Game::getBulletName() const
{
    return tanks.at(currentTankNumber)->getBulletName();
}

void Game::createTank(int xcoordinate, QColor color)
{
    QPointF tankPointOnScene = landscape->getPointWithXCoordinate(xcoordinate) + QPointF(0, -Tank::getRadius());
    tanks.append(new Tank(this, tankPointOnScene, color));
    connect(tanks.last(), SIGNAL(changedHealth(int, QColor)), this, SIGNAL(changedHealth(int, QColor)));
    connect(tanks.last(), SIGNAL(gameIsOver(QColor)), this, SIGNAL(gameIsOver(QColor)));
}

QGraphicsScene *Game::getScene() const
{
    return scene;
}

QPointF Game::getPointWithXCoordinate(qreal x)
{
    return landscape->getPointWithXCoordinate(x);
}
