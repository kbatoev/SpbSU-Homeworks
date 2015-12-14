#include "keyController.h"
#include "game.h"

KeyController::KeyController(Tank *currentTank, Landscape *currentLandscape, Game *game)
{
    this->game = game;
    controllableTank = currentTank;
    landscape = currentLandscape;
}

void KeyController::handleKey(QKeyEvent *keyEvent)
{
    QPointF oldPoint = controllableTank->getCenter();
    QPointF point = oldPoint;
    if (keyEvent->key() == Qt::Key_Left)
    {
        point = landscape->getPointWithXCoordinate(oldPoint.x() - controllableTank->getSpeed());
        point.setY(point.y() - controllableTank->getRadius());
        if (point.x() > 0 && point.x() < widthOfFrame && point.y() > 0 && point.y() < heightOfFrame)
            controllableTank->setCenter(point);
    }

    if (keyEvent->key() == Qt::Key_Right)
    {
        point = landscape->getPointWithXCoordinate(oldPoint.x() + controllableTank->getSpeed());
        point.setY(point.y() - controllableTank->getRadius());
        if (point.x() > 0 && point.x() < widthOfFrame && point.y() > 0 && point.y() < heightOfFrame)
            controllableTank->setCenter(point);
    }

    if (keyEvent->key() == Qt::Key_Up)
    {
        controllableTank->increaseAngle();
    }

    if (keyEvent->key() == Qt::Key_Down)
    {
        controllableTank->decreaseAngle();
    }

    if (keyEvent->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet(controllableTank->getCenter(), controllableTank->getGunAngleInRadians(),
                                    landscape, game->getScene());
        game->addBullet(bullet);
        //game->getScene()->addItem(bullet);
        bullet->fly();
    }
}

