#include "keyController.h"
#include "game.h"

KeyController::KeyController(Game *game)
    : game(game)
{
}

void KeyController::handleKey(QKeyEvent *keyEvent)
{
    Tank *tank = game->getTank();
    Landscape *landscape = game->getLandscape();

    QPointF oldPoint = tank->getCenter();
    QPointF point = oldPoint;
    if (keyEvent->key() == Qt::Key_Left)
    {
        point = landscape->getPointWithXCoordinate(oldPoint.x() - tank->getSpeed());
        point.setY(point.y() - tank->getRadius());
        if (point.x() > 0 && point.x() < widthOfFrame && point.y() > 0 && point.y() < heightOfFrame)
        {
            tank->setCenter(point);
        }
    }

    if (keyEvent->key() == Qt::Key_Right)
    {
        point = landscape->getPointWithXCoordinate(oldPoint.x() + tank->getSpeed());
        point.setY(point.y() - tank->getRadius());
        if (point.x() > 0 && point.x() < widthOfFrame && point.y() > 0 && point.y() < heightOfFrame)
        {
            tank->setCenter(point);
        }
    }

    if (keyEvent->key() == Qt::Key_Up)
    {
        tank->increaseAngle();
    }

    if (keyEvent->key() == Qt::Key_Down)
    {
        tank->decreaseAngle();
    }

    if (keyEvent->key() == Qt::Key_Enter)
    {
        Bullet *bullet = new Bullet(tank->getCenter(), tank->getGunAngleInRadians(), game);
        bullet->addYourselfToScene();
        bullet->fly();
    }

}

