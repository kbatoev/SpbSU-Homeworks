#include "landscape.h"

Landscape::Landscape() : numberPoints(26)
{
    generateRandomLandscape();
}

Landscape::~Landscape()
{
}

QRectF Landscape::boundingRect() const
{
    //QPointF topLeft(0, 0);
    //QPointF bottomRight(widthOfFrame, heightOfFrame);
    //return QRectF(topLeft, bottomRight);
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

QPointF Landscape::getPointWithXCoordinate(qreal x)
{
    int j = 1;
    while (!(x >= points[j - 1].x() && x <= points[j].x()))
    {
        j++;
    }
    QPointF firstPoint = points[j - 1];
    QPointF secondPoint = points[j];
    qreal y = firstPoint.y() +
            (secondPoint.y() - firstPoint.y()) * (x - firstPoint.x()) / (secondPoint.x() - firstPoint.x());
    return QPointF(x, y);
}

void Landscape::generateRandomLandscape()
{
    srand(time(0));
    int length = widthOfFrame / (numberPoints - 1);
    points.resize(numberPoints);
    for (int i = 0; i < numberPoints; ++i)
    {
        points[i].setX(length * i);
        do
        {
            points[i].setY(rand() % moduleForYCoordinate + yCoordinateAdding);
        } while(i && abs(points[i - 1].y() - points[i].y()) > maxDistanceBetweenTwoYCoordinates);
    }
}

