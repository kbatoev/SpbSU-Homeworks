#include "landscape.h"

Landscape::Landscape(QVector<QPointF> *serverPoints)
{
    if (serverPoints)
    {
        points = new QVector<QPointF>;
        numberPoints = serverPoints->size();
        for (int i = 0; i < serverPoints->size(); i++)
        {
            this->points->append(serverPoints->at(i));
        }
    }
    else
    {
        points = new QVector<QPointF>;
        numberPoints = widthOfFrame / interval + 1;
        generateRandomLandscape();
    }
}

Landscape::~Landscape()
{
}

QRectF Landscape::boundingRect() const
{
    return QRectF(QPointF(0, 0), QPointF(0, 0));
}

void Landscape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setWidth(4);
    pen.setColor(Qt::green);
    painter->setPen(pen);
    for (int i = 1; i < numberPoints; i++)
    {
        painter->drawLine(points->at(i - 1), points->at(i));
    }
}

QPointF Landscape::getPointWithXCoordinate(qreal x)
{
    int j = 1;
    while (!(x >= points->at(j - 1).x() && x <= points->at(j).x()))
        j++;

    QPointF firstPoint = points->at(j - 1);
    QPointF secondPoint = points->at(j);
    qreal y = firstPoint.y() +
            (secondPoint.y() - firstPoint.y()) * (x - firstPoint.x()) / (secondPoint.x() - firstPoint.x());

    return QPointF(x, y);
}

void Landscape::generateRandomLandscape()
{
    srand(time(0));
    int length = widthOfFrame / (numberPoints - 1);

    QPointF currentPoint;
    for (int i = 0; i < numberPoints; ++i)
    {
        currentPoint.setX(length * i);
        do
        {
            currentPoint.setY(rand() % moduleForYCoordinate + yCoordinateAdding);
        } while(i && abs(currentPoint.y() - points->at(i - 1).y()) > maxDistanceBetweenTwoYCoordinates);
        points->append(currentPoint);
    }
}

int Landscape::getNumberPoints() const
{
    return numberPoints;
}

QVector<QPointF> *Landscape::getPoints() const
{
    return points;
}

