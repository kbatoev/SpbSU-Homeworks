#pragma once

#include "burstable.h"
#include <QGraphicsEllipseItem>

#include <QPen>
#include <QPainter>

class Tank : public Burstable
{
public:
    Tank(int xCoordiante, int yCoordinate);
    Tank(QPointF point);
    ~Tank();
    QGraphicsEllipseItem *getGeometry();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void drawBurst();

    int getSpeed() const;
    QPointF getCenter() const;
    //void setCenter(QPointF newCenter);

private:
    QPointF center;
    static const int radius = 15;
    int speed;
};

