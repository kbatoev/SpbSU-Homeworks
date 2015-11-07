#pragma once

#include <stdlib.h>
#include <time.h>

#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QGraphicsItem>

const int widthOfFrame = 1000;
const int lengthOfFrame = 700;

const int yCoordinateAdding = 150;
const int maxDistanceBetweenTwoYCoordinates = 70;
const int moduleForYCoordinate = 500;


class Landscape : public QGraphicsItem
{
public:
    Landscape();
    ~Landscape();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    void generateRandomLandscape();


    QVector<QPointF> points;
    int numberPoints;
};
