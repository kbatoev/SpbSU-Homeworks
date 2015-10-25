#pragma once

#include <stdlib.h>
#include <time.h>

#include <QPolygonF>
#include <QPoint>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QGraphicsItem>

class Landscape : public QGraphicsItem
{
public:
    Landscape();
    ~Landscape();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QVector<QPointF> points;
    int numberPoints;
};
