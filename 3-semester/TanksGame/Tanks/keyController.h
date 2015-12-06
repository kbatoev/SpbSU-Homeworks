#pragma once

#include <QKeyEvent>
#include "landscape.h"
#include "tank.h"

class KeyController
{
public:
    KeyController(Tank *currentTank, Landscape *currentLanscape);

    void handleKey(QKeyEvent *keyEvent);

private:
    Tank *controllableTank;
    Landscape *landscape;
};
