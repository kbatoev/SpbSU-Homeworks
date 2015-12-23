#pragma once

#include <QPen>
#include <QRectF>
#include <QPainter>

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QPointF>

#include "../Constants/constants.h"
#include "burstable.h"

/**
 * @brief The Burst class
 * It is created by Bullet class
 */

class Burst : public QObject, public Burstable
{
    Q_OBJECT

public:
    Burst(QPointF center, QGraphicsScene *scene, int radius, int damage);
    ~Burst();

    /// it depends on initialRadius and iteration
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void drawBurst(Burstable *reason);
    int makeDamage();

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


    int damage;
};

