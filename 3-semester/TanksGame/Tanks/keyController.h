#pragma once

#include <QKeyEvent>

#include "landscape.h"
#include "tank.h"
#include "bullet.h"

class Game;

class KeyController
{
public:
    KeyController(Tank *currentTank, Landscape *currentLanscape, Game *game);

    void handleKey(QKeyEvent *keyEvent);

private:
    Tank *controllableTank;
    Landscape *landscape;
    Game *game;
};
