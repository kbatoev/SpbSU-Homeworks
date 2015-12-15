#pragma once

#include <QPen>
#include <QPainter>

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QPointF>

#include "../Constants/constants.h"

class Burst : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Burst(QPointF center, QGraphicsScene *scene, int radius);
    ~Burst();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    void updateStatusOfBurst();

private slots:
    void incrementIteration();

private:
    QPointF burstCenter;
    QGraphicsScene *scene;
    int maxBurstRadius;
    int initialRadius;
    int iteration;
    bool isOver;
    QTimer *timer;
};

