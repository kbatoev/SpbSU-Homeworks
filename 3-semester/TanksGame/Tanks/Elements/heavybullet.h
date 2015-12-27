#pragma once

#pragma once

#include "bullet.h"

class HeavyBullet : public Bullet
{
    Q_OBJECT

public:
    HeavyBullet(Game *game);
    ~HeavyBullet();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

