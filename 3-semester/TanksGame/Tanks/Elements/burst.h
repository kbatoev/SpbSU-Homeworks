#pragma once

#include <QPen>
#include <QRectF>
#include <QPainter>

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QPointF>

#include "../Constants/constants.h"
#include "contactable.h"

/**
 * @brief The Burst class
 * It is created by Bullet class
 */

const int additionToRadius = 5;

class Burst : public QObject, public Contactable
{
    Q_OBJECT

public:
    Burst(QGraphicsScene *scene, int radius, int damage);
    ~Burst();

    /// it depends on initialRadius and iteration
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void start();
    void isContactedBy(Contactable *reason);
    int makeDamage();

    void setBurstCenter(const QPointF &value);

private slots:
    /// checks if burst is over
    void updateStatusOfBurst();

private:
    QPointF burstCenter;
    QGraphicsScene *scene;
    int maxBurstRadius;
    int currentRadius;
    int iteration;
    bool isOver;
    QTimer *timer;

    int damage;
};

