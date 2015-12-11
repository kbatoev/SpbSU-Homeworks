#pragma once

#include "burstable.h"
#include <QGraphicsEllipseItem>

#include <QPen>
#include <QPainter>

const qreal PI = 3.141592653;

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
    qreal getGunAngleInRadians() const;
    static int getRadius();

    void setCenter(QPointF newCenter);
    void increaseAngle();
    void decreaseAngle();

    QPointF getStartPointForBullet() const;

private:
    void drawGun(QPainter *painter);
    QPointF normalize(QPointF point);

    QPointF center;
    QPointF startPointForBullet;
    static const int radius = 15;
    int speed;

    qreal gunAngle;
};

