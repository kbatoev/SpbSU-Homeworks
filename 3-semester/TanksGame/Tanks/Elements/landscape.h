#pragma once

#include <stdlib.h>
#include <time.h>

#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QGraphicsItem>

#include "../Constants/constants.h"


/**
 * @brief The Landscape class
 * Generates points with Random
 */

class Landscape : public QGraphicsItem
{
public:
    Landscape();
    Landscape(QVector<QPointF> serverPoints);
    ~Landscape();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF getPointWithXCoordinate(qreal x);

private:
    void generateRandomLandscape();

    QVector<QPointF> points;
    int numberPoints;
};
