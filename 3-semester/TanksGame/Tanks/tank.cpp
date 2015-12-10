#include "tank.h"

Tank::Tank(int xCoordiante, int yCoordinate)
{
    center = QPointF(xCoordiante, yCoordinate);
    speed = 10;
    gunAngle = -45.0;
}

Tank::Tank(QPointF point)
{
    center = point;
    speed = 10;
    gunAngle = -45.0;
}

Tank::~Tank()
{
}

QGraphicsEllipseItem *Tank::getGeometry()
{

}

QRectF Tank::boundingRect() const
{
    return QRectF(center.x() - radius, center.y() - radius,
                  center.x() + radius, center.y() + radius);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::yellow);
    pen.setWidth(4);
    painter->setPen(pen);

    //painter->drawRect(center.x() - radius, center.y() - radius, radius, radius);
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

void Tank::setCenter(QPointF newCenter)
{
    center = newCenter;
}

int Tank::getRadius()
{
    return radius;
}

void Tank::drawGun(QPainter *painter)
{
    qreal length = 20;
    qreal width = 7;

    //painter->drawLine(points[i - 1], points[i]);

    qreal angle = PI / 180.0 * gunAngle;
    qreal cosinus = ::cos(PI / 2.0 + angle);
    qreal sinus = ::sin(PI / 2.0 + angle);
    QPointF p1(width * ::cos(PI / 2.0 + angle), width * ::sin(PI / 2.0 + angle));
    QPointF p2(0, 0);
    QPointF p3(length * ::cos(angle), length * ::sin(angle));
    QPointF p4 = p1 + p3;

    p1 += center;
    p2 += center;
    p3 += center;
    p4 += center;

    painter->drawLine(p1, p2);
    painter->drawLine(p2, p3);
    painter->drawLine(p3, p4);
    painter->drawLine(p4, p1);
}

