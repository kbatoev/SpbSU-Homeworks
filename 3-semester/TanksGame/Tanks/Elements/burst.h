#pragma once

#include <QPen>
#include <QPainter>

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QPointF>

#include "../Constants/constants.h"

/**
 * @brief The Burst class
 * It is created by Bullet class
 */

class Burst : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Burst(QPointF center, QGraphicsScene *scene, int radius);
    ~Burst();

    /// it depends on initialRadius and iteration
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    /// checks if burst is over
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

