#include "keyController.h"

KeyController::KeyController(Tank *currentTank, Landscape *currentLandscape)
{
    controllableTank = currentTank;
    landscape = currentLandscape;
}

void KeyController::handleKey(QKeyEvent *keyEvent)
{
    QPointF point = controllableTank->pos();
    if (keyEvent->key() == Qt::Key_A)
    {
        point = landscape->getPointWithXCoordinate(controllableTank->x() - controllableTank->getSpeed());
    }

    if (keyEvent->key() == Qt::Key_D)
    {
        point = landscape->getPointWithXCoordinate(controllableTank->x() + controllableTank->getSpeed());
    }
    controllableTank->setPos(point);
}

