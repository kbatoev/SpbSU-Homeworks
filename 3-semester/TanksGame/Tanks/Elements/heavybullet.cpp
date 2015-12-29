#include "heavybullet.h"
#include "../game.h"

HeavyBullet::HeavyBullet(Game *game)
    : Bullet(game)
{
    bulletRadius = 7;
    coefficient = 4.0;
    speed = 50;
    damage = 40;
    radiusOfBurst = 60;

    burst = new Burst(this->game->getScene(), radiusOfBurst, damage);
}

HeavyBullet::~HeavyBullet()
{
    delete burst;
}

void HeavyBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::cyan);
    pen.setWidth(4);
    painter->setPen(pen);
    Bullet::paint(painter, option, widget);
}

QString HeavyBullet::getName()
{
    return "Heavy bullet";
}
