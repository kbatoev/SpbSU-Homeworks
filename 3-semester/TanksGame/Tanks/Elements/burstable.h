#pragma once

#include <QGraphicsItem>

class Burstable : public QGraphicsItem
{
public:
    virtual void drawBurst(Burstable *reason = 0) = 0;
    virtual int makeDamage() = 0;

protected:
    bool hasBurst = false;
    int radiusOfBurst;
};
