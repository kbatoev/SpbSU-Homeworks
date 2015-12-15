#include "tank.h"

Tank::Tank(int xCoordiante, int yCoordinate) : Tank()
{
    center = QPointF(xCoordiante, yCoordinate);
}

Tank::Tank(QPointF point) : Tank()
{
    center = point;
}

Tank::Tank() : speed(10), gunAngle(-45.0)
{

}

Tank::~Tank()
{
}

QGraphicsEllipseItem *Tank::getGeometry()
{

}

QRectF Tank::boundingRect() const
{
    return QRectF(center.x() - radius, center.y() - radius, 2 * radius, 2 * radius);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::yellow);
    pen.setWidth(4);
    painter->setPen(pen);

    painter->drawEllipse(center, radius, radius);
    drawGun(painter);
}

void Tank::drawBurst()
{

}

int Tank::getSpeed() const
{
    return speed;
}

QPointF Tank::getCenter() const
{
    return center;
}

qreal Tank::getGunAngleInRadians() const
{
    return gunAngle * PI / degreesInPI;
}

void Tank::setCenter(QPointF newCenter)
{
    center = newCenter;
}

void Tank::increaseAngle()
{
    if (gunAngle > -leftBorderForGun)
        gunAngle -= addingToAngle;
}

void Tank::decreaseAngle()
{
    if (gunAngle < rightBorderForGun)
        gunAngle += addingToAngle;
}


int Tank::getRadius()
{
    return radius;
}

void Tank::drawGun(QPainter *painter)
{
    qreal angle = PI / degreesInPI * gunAngle;
    QPointF p1(width * ::cos(PI / 2.0 + angle), width * ::sin(PI / 2.0 + angle));
    QPointF p2(0, 0);
    QPointF p3(length * ::cos(angle), length * ::sin(angle));
    QPointF p4 = p1 + p3;

    QPointF normalizedVector = normalize(p3);
    qreal bulletRadius = 5.0;
    startPointForBullet = (p4 + p3) / 2.0 + normalizedVector * bulletRadius;

    p1 += center;
    p2 += center;
    p3 += center;
    p4 += center;
    startPointForBullet += center;

    painter->drawLine(p1, p2);
    painter->drawLine(p2, p3);
    painter->drawLine(p3, p4);
    painter->drawLine(p4, p1);

}

QPointF Tank::normalize(QPointF point)
{
    qreal x = point.x();
    qreal y = point.y();
    qreal length = sqrt(x * x + y * y);
    return QPointF(x / length, y / length);
}

QPointF Tank::getStartPointForBullet() const
{
    return startPointForBullet;
}
