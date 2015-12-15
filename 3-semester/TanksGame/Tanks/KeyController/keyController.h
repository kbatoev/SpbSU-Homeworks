#pragma once

#include <QKeyEvent>

class Game;

class KeyController
{
public:
    KeyController(Game *game);

    void handleKey(QKeyEvent *keyEvent);

private:
    Game *game;
};
