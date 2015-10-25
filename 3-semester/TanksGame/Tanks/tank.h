#pragma once

#include "burstable.h"
#include <QGraphicsEllipseItem>

#include <QPen>
#include <QPainter>

class Tank : public Burstable
{
public:
    Tank();
    ~Tank();
    QGraphicsEllipseItem *getGeometry();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void drawBurst();

private:
    QPointF center;
    const int rx = 25;
    const int ry = 25;
};

