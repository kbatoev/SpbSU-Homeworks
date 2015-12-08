#include "keyController.h"

KeyController::KeyController(Tank *currentTank, Landscape *currentLandscape)
{
    controllableTank = currentTank;
    landscape = currentLandscape;
}

void KeyController::handleKey(QKeyEvent *keyEvent)
{
    QPointF oldPoint = controllableTank->getCenter();
    QPointF point = oldPoint;
    if (keyEvent->key() == Qt::Key_A)
    {
        point = landscape->getPointWithXCoordinate(oldPoint.x() - controllableTank->getSpeed());
        point.setY(point.y() - controllableTank->getRadius());
        controllableTank->setCenter(point);
    }

    if (keyEvent->key() == Qt::Key_D)
    {
        point = landscape->getPointWithXCoordinate(oldPoint.x() + controllableTank->getSpeed());
        point.setY(point.y() - controllableTank->getRadius());
        controllableTank->setCenter(point);
    }
}

