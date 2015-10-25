#pragma once

#include <QGraphicsScene>

#include "landscape.h"
#include "tank.h"

class Game
{
public:
    Game();
    ~Game();
    QGraphicsScene *getScene();

private:
    QGraphicsScene *scene;
    Landscape *landscape;
    Tank *tank;
};

