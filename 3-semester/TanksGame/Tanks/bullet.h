#pragma once

#include "burstable.h"
#include <QGraphicsItem>
#include <QPen>
#include <QPainter>
#include <QObject>
#include <QTimer>

#include "landscape.h"

class Bullet : public QObject, public Burstable
{
    Q_OBJECT
public:
    Bullet(QPointF center, qreal angle, Landscape *landscape);

    void drawBurst();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void fly();

public slots:
    void updatePosition();

private:
    void checkDistanceFromLandscape();
    qreal countDistanceFromBulletCenter(QPointF point);

private:
    QPointF bulletCenter;
    QPointF initialCenter;
    int iteration;
    int bulletRadius;
    int msec;
    qreal angle;
    qreal speed;
    QTimer *timer;
    Landscape *landscape;
};
