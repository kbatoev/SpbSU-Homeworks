#include "tank.h"

Tank::Tank()
{
    center = QPointF(50, 50);
}

Tank::~Tank()
{
}

QGraphicsEllipseItem *Tank::getGeometry()
{
}

QRectF Tank::boundingRect() const
{
    return QRectF(0, 0, 200, 300);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::yellow);
    pen.setWidth(4);
    painter->setPen(pen);
    painter->drawEllipse(center, rx, ry);
}

void Tank::drawBurst()
{

}

