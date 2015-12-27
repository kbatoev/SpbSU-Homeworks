#include "lightbullet.h"
#include "../game.h"


LightBullet::LightBullet(Game *game)
    : Bullet(game)
{
    bulletRadius = 5;
    coefficient = 4.0;
    speed = 70;
    damage = 10;
    radiusOfBurst = 20;

    burst = new Burst(this->game->getScene(), radiusOfBurst, damage);
}

LightBullet::~LightBullet()
{
    delete burst;
}

void LightBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::magenta);
    pen.setWidth(2);
    painter->setPen(pen);
    Bullet::paint(painter, option, widget);
}
