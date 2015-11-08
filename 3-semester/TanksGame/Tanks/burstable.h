#pragma once

#include <QGraphicsItem>

class Burstable : public QGraphicsItem
{
public:
    virtual void drawBurst() = 0;
private:
    int radiusOfBurst;
};
