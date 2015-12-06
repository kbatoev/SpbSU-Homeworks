#include "tank.h"

Tank::Tank(int xCoordiante, int yCoordinate)
{
    center = QPointF(xCoordiante, yCoordinate);
    speed = 10;
}

Tank::Tank(QPointF point)
{
    center = point;
    speed = 10;
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
    painter->drawEllipse(center, radius, radius);
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

/*void Tank::setCenter(QPointF newCenter)
{
    center = newCenter;
}*/

