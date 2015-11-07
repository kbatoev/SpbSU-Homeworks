#include "game.h"

Game::Game()
{
    scene = new QGraphicsScene();
    landscape = new Landscape();
    tank = new Tank(10, 10);
    scene->addItem(landscape);
    scene->addItem(tank);
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

