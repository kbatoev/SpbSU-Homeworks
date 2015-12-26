#include "heavybullet.h"
#include "../game.h"

HeavyBullet::HeavyBullet(QPointF center, qreal angle, Game *game)
{
    this->game = game;
    bulletCenter = center;
    initialCenter = center;
    this->angle = angle;
    iteration = 0;
    bulletRadius = 7;
    coefficient = 3.0;
    speed = 55;

    timer = nullptr;
    isReadyToBurst = false;

    damage = 40;

    radiusOfBurst = 60;
    this->game->addBullet(this);
}

HeavyBullet::~HeavyBullet()
{

}

void HeavyBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::cyan);
    pen.setWidth(4);
    painter->setPen(pen);
    painter->drawEllipse(bulletCenter, bulletRadius, bulletRadius);
}
