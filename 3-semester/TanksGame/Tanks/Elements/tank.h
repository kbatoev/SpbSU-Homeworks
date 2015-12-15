#pragma once

#include <QGraphicsEllipseItem>
#include <QPen>
#include <QPainter>

#include "burstable.h"
#include "../Constants/constants.h"

class Tank : public Burstable
{
public:
    Tank(int xCoordiante, int yCoordinate);
    Tank(QPointF point);
    Tank();
    ~Tank();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void drawBurst();

    /// Getters
    int getSpeed() const;
    QPointF getCenter() const;
    qreal getGunAngleInRadians() const;
    static int getRadius();

    /// changes position of tank in QGraphicsScene
    void setCenter(QPointF newCenter);
    void increaseAngle();
    void decreaseAngle();

    /// get the point in the end of Gun
    QPointF getStartPointForBullet() const;

private:
    void drawGun(QPainter *painter);

    /// normalizes vector with the beginning - (0, 0) and end - point
    QPointF normalize(QPointF point);

    QPointF center;
    QPointF startPointForBullet;
    static const int radius = 15;
    int speed;

    qreal gunAngle;
};

