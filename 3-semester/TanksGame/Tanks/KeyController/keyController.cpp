#include "keyController.h"
#include "game.h"

KeyController::KeyController(Game *game)
    : game(game)
{
}

void KeyController::handleKey(QKeyEvent *keyEvent)
{
    Tank *tank = game->getCurrentTank();
    Landscape *landscape = game->getLandscape();

    QPointF oldPoint = tank->getCenter();
    QPointF point = oldPoint;
    if (keyEvent->key() == Qt::Key_A)
    {
        point = landscape->getPointWithXCoordinate(oldPoint.x() - tank->getSpeed());
        point.setY(point.y() - tank->getRadius());
        if (point.x() > 0 && point.x() < widthOfFrame && point.y() > 0 && point.y() < heightOfFrame)
            tank->setCenter(point);
    }

    if (keyEvent->key() == Qt::Key_D)
    {
        point = landscape->getPointWithXCoordinate(oldPoint.x() + tank->getSpeed());
        point.setY(point.y() - tank->getRadius());
        if (point.x() > 0 && point.x() < widthOfFrame && point.y() > 0 && point.y() < heightOfFrame)
            tank->setCenter(point);
    }

    if (keyEvent->key() == Qt::Key_W)
    {
        tank->increaseAngle();
    }

    if (keyEvent->key() == Qt::Key_S)
    {
        tank->decreaseAngle();
    }

    if (keyEvent->key() == Qt::Key_Enter)
    {
        tank->shoot();
        game->currentTankShot();
    }

    if (keyEvent->key() == Qt::Key_Q)
    {
        tank->changeBullet();
    }
}

