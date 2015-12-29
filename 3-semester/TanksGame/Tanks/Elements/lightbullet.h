#pragma once

#include "bullet.h"

class LightBullet : public Bullet
{
    Q_OBJECT

public:
    LightBullet(Game *game);
    ~LightBullet();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QString getName();
};
