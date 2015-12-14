#pragma once

#include <QKeyEvent>

#include "landscape.h"
#include "tank.h"
#include "bullet.h"

class Game;

class KeyController
{
public:
    KeyController(Game *game);

    void handleKey(QKeyEvent *keyEvent);

private:
    Game *game;
};
