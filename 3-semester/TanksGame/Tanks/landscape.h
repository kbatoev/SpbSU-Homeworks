#pragma once

#include <stdlib.h>
#include <time.h>

#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QGraphicsItem>

#include "constants.h"

class Landscape : public QGraphicsItem
{
public:
    Landscape();
    ~Landscape();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF getPointWithXCoordinate(qreal x);

private:
    void generateRandomLandscape();

    QVector<QPointF> points;
    int numberPoints;
};
