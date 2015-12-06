#pragma once

#include "burstable.h"
#include <QGraphicsEllipseItem>

#include <QPen>
#include <QPainter>

class Tank : public Burstable
{
public:
    Tank(int xCoordiante, int yCoordinate);
    ~Tank();
    QGraphicsEllipseItem *getGeometry();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void drawBurst();

    int getSpeed() const;

private:
    QPointF center;
    static const int radius = 15;

    int speed;
};

