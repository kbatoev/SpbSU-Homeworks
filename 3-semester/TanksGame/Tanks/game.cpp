#include "game.h"

Game::Game()
{
    scene = new QGraphicsScene();
    landscape = new Landscape();
    scene->addItem(landscape);
    //landscape->setFlags(QGraphicsItem::ItemIsMovable);
}

Game::~Game()
{
    delete landscape;
    delete scene;
}

QGraphicsScene *Game::getScene()
{
    return scene;
}

