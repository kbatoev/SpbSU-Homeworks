#include "landscape.h"

Landscape::Landscape()
{
    srand(time(0));
    numberPoints = 50;
    int length = 20;
    points.resize(numberPoints);
    for (int i = 0; i < numberPoints; ++i)
    {
        points[i].setX(length * i);
        if (!i)
        {
            points[i].setY(rand() % 500 + 150);
        }
        else
        do
        {
            points[i].setY(rand() % 500 + 150);
        } while(abs(points[i - 1].y() - points[i].y()) > 50);
    }
}

Landscape::~Landscape()
{
}

QRectF Landscape::boundingRect() const
{
    QPointF topLeft(0, 0);
    QPointF bottomRight(1000, 700);
    return QRectF(topLeft, bottomRight);
}

void Landscape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setWidth(4);
    pen.setColor(Qt::green);
    painter->setPen(pen);
    for (int i = 1; i < numberPoints; i++)
    {
        painter->drawLine(points[i - 1], points[i]);
    }
}

