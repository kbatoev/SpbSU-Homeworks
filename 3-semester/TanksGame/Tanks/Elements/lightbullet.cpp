#include "lightbullet.h"
#include "../game.h"


LightBullet::LightBullet(QPointF center, qreal angle, Game *game)
{
    this->game = game;
    bulletCenter = center;
    initialCenter = center;
    this->angle = angle;
    iteration = 0;
    bulletRadius = 5;
    coefficient = 4.0;
    speed = 70;

    timer = nullptr;
    isReadyToBurst = false;

    damage = 10;

    radiusOfBurst = 20;
    this->game->addBullet(this);
}

LightBullet::~LightBullet()
{

}

void LightBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::magenta);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawEllipse(bulletCenter, bulletRadius, bulletRadius);
}
